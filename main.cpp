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
		return;
	}
	if(s[index] == '?')
	{
		string a,b,c = result;
		dfs(s, a.push_back('a'), index + 1);
		dfs(s, b.push_back('b'), index + 1);
		dfs(s, c.push_back('c'), index + 1);
	}else{
		dfs(s, result.push_back(s[index]), index + 1);
	}
	return;
}

void test(string &s)
{
	dfs(s, "", 0);
	for(auto e : cand)
	{
		cout << e << endl;
	}
}

int main()
{
	typedef long long int ll;
	string s;
	cin >> s;
	vector<ll> bccount(s.size(), 0);
	vector<ll> ccount(s.size(), 0);
	vector<ll> abccount(s.size(), 0);
	ll mod = 1000000000 + 7;
	//store the number of C after the index i
	if(s.back() == 'C' || s.back() == '?')
	{
		ccount[s.size() - 1] = 1;
	}
	for(int i = s.size() - 2; i >= 0; i--)
	{
		if(s[i] == 'C')
		{
			ccount[i] = (ccount[i + 1] + 1) % mod;
		}else if(s[i] == '?')
		{
			ccount[i] = (ccount[i] + ccount[i + 1]) % mod;
			ccount[i] = (ccount[i] + ccount[i + 1]) % mod;
			ccount[i] = (ccount[i] + ccount[i + 1] + 1) % mod;
		}else{
			ccount[i] = ccount[i + 1];
		}
	}
	//store the number of BC after the index i
	ll result = 0;
	for(int i = s.size() - 2; i >= 0; i--){
		if(s[i] == 'B')
		{
			bccount[i] = (bccount[i + 1] + ccount[i + 1]) % mod;
		}else if(s[i] == '?')
		{
			bccount[i] = (bccount[i + 1] + ccount[i + 1]) % mod;
			bccount[i] = (bccount[i] + bccount[i + 1]) % mod;
			bccount[i] = (bccount[i] + bccount[i + 1]) % mod;
		}else{
			bccount[i] = bccount[i + 1];
		}
	}

	for(auto e : ccount)
	{
		cout << e << endl;
	}
	cout << endl;

	for(auto e : bccount)
	{
		cout << e << endl;
	}

	for(int i = s.size() - 3; i >= 0; i--){
		if(s[i] == 'A')
		{
			abccount[i] = (abccount[i + 1] + bccount[i + 1]) % mod;
		}else if(s[i] == '?')
		{
			abccount[i] = (abccount[i] + abccount[i + 1]) % mod;
			abccount[i] = (abccount[i] + abccount[i + 1]) % mod;		
			abccount[i] = (abccount[i + 1] + bccount[i + 1]) % mod;
		}else{
			abccount[i] = abccount[i + 1];
		}
	}
	cout << endl;

	for(auto e : abccount)
	{
		cout << e << endl;
	}

	cout << abccount[0] << endl;

	test(s);
	return 0;
}
