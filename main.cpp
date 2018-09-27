#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<string> cand;

void dfs(string &s, string result, int index)
{
	if(index == s.size())
	{
		cand.push_back(result);
		cout << result << endl;
		return;
	}
	if(s[index] == '?')
	{
		string a,b,c;
		a = b = c = result;
		a.push_back('A');
		b.push_back('B');
		c.push_back('C');
		dfs(s, a, index + 1);
		dfs(s, b, index + 1);
		dfs(s, c, index + 1);
	}else{
		result.push_back(s[index]);
		dfs(s, result, index + 1);
	}
	return;
}

void test(string &s)
{
	dfs(s, "", 0);
	int count = 0;
	for(auto e : cand)
	{
	    for(int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j < s.size(); ++j) {
                for (int k = j + 1; k < s.size(); ++k) {
                    if(e[i] == 'A' && e[j] == 'B' && e[k] == 'C')
                    {
                        count++;
                    }
                }
            }
        }
	}
	cout << count << endl;
}

int main()
{
	typedef long long int ll;
	string s;
	cin >> s;
	vector<vector<ll>> dp(s.size() + 1, vector<ll>(4, 0));
	dp[s.size()][3] = 1;
	ll mod = 1000000000 + 7;
	string check = "ABC";
    for (int i = s.size() - 1; i >= 0 ; i--) {
        for (int j = 0; j < 4; ++j) {
            if(j == 3)
            {
                if(s[i] == '?')
                {
                    dp[i][j] = 3 * dp[i + 1][j];
                    dp[i][j] %= mod;
                }else{
                    dp[i][j] = dp[i + 1][j];
                }
            }else{
                int m1, m2;
                m1 = s[i] == '?' ? 3 : 1;
                m2 = s[i] == '?' || check[j] == s[i] ? 1 : 0;
                dp[i][j] = m1 * dp[i + 1][j] + m2 * dp[i + 1][j + 1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[0][0] << endl;
	return 0;
}