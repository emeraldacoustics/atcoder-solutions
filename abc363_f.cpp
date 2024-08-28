#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const int maxS = 1000;

string reverse_string(string s)
{
	reverse(s.begin(), s.end());
	return s;
}

bool contains_zero(long long x)
{
	string s = to_string(x);
	for (const auto & c : s)
	{
		if (c == '0')
			return true;
	}
	return false;
}

bool is_palindrome(long long x)
{
	string s = to_string(x);
	string t = s;
	reverse(t.begin(), t.end());

	return s == t;
}

bool is_palindrome(long long x, long long y)
{
	string s = to_string(x);
	string t = to_string(y);
	reverse(t.begin(), t.end());

	return s == t;
}

int main()
{
	ios::sync_with_stdio(false);

	long long N;
	cin >> N;

	vector<long long> divisors;
	for (int i = 1; i <= N / i; i++)
	{
		if (N % i == 0)
		{
			divisors.push_back(i);
			if (i < N / i)
				divisors.push_back(N / i);
		}
	}

	sort(divisors.begin(), divisors.end());
	map<long long, int> dividx;
	for (int i = 0; i < divisors.size(); i++)
		dividx[divisors[i]] = i;

	vector<vector<int> > vpalindromes(divisors.size());
	vector<vector<string> > vpalindromestring(divisors.size());
	for (int i = 0; i < divisors.size(); i++)
	{
		for (int k = 0; k <= i && divisors[k] <= divisors[i] / divisors[k]; k++)
		{
			if (divisors[i] % divisors[k] == 0)
			{
				long long x = divisors[k];
				long long y = divisors[i] / divisors[k];
				if (is_palindrome(x, y) && !contains_zero(x))
				{
					vpalindromes[i].push_back(to_string(x).length());
					vpalindromestring[i].push_back(to_string(x));
					if (x != y)
					{
						vpalindromes[i].push_back(to_string(y).length());
						vpalindromestring[i].push_back(to_string(y));
					}
				}
			}
		}
	}

	vector<vector<pair<int, int> > > prv(divisors.size());
	for (int i = 0; i < divisors.size(); i++)
	{
		for (int k = 0; k <= i; k++)
		{
			if (divisors[i] % divisors[k])
				continue;

			int z = dividx[divisors[i] / divisors[k]];
			for (const auto & l : vpalindromes[k])
				prv[i].emplace_back(l * 2 + 2, z);
		}
	}

	// vector<vector<long long> > dp(maxS + 1, vector<long long>(divisors.size()));
	// for (int i = 0; i < divisors.size(); i++)
	// {
	// 	if (is_palindrome(divisors[i]) && !contains_zero(divisors[i]))
	// 		dp[to_string(divisors[i]).length()][i]++;
	// 	for (const auto & l : vpalindromes[i])
	// 		dp[l * 2 + 1][i]++;
	// }
	// for (int l = 5; l <= maxS; l++)
	// {
	// 	for (int i = 0; i < divisors.size(); i++)
	// 	{
	// 		for (const auto & p : prv[i])
	// 		{
	// 			if (l >= p.first)
	// 				dp[l][i] += dp[l - p.first][p.second];
	// 		}
	// 	}
	// }

	// long long ans = 0;
	// for (int i = 0; i <= maxS; i++)
	// 	ans += dp[i][divisors.size() - 1];
	// cout << ans << endl;

	vector<string> dp(divisors.size());
	for (int i = 0; i < divisors.size(); i++)
	{
		if (is_palindrome(divisors[i]) && !contains_zero(divisors[i]))
			dp[i] = to_string(divisors[i]);
		else if (!vpalindromes[i].empty())
			dp[i] = vpalindromestring[i][0] + "*" + reverse_string(vpalindromestring[i][0]);
		else
		{
			for (const auto & p : prv[i])
			{
				if (p.second == i)
					continue;
				if (dp[p.second] != "")
				{
					int k = dividx[divisors[i] / divisors[p.second]];
					dp[i] = vpalindromestring[k][0] + "*" + dp[p.second] + "*" + reverse_string(vpalindromestring[k][0]);
					break;
				}
			}
		}
	}

	string ans = dp.back();
	if (ans == "")
		ans = "-1";
	cout << ans << endl;

	return 0;
}
