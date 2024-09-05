#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char idmap[] = "RPS";

int convert(const char & C)
{
	if (C == 'R')
		return 0;
	else if (C == 'P')
		return 1;
	else if (C == 'S')
		return 2;
}

int fight(const char & A, const char & B)
{
	if (A == B)
		return 0;
	else if (A == 'R')
		return B == 'P' ? -1 : 1;
	else if (A == 'P')
		return B == 'S' ? -1 : 1;
	else if (A == 'S')
		return B == 'R' ? -1 : 1;
	else
		return 0;
}

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	string S;
	cin >> S;

	vector<vector<int> > dp(N, vector<int>(3, -1));
	for (int i = 0; i < 3; i++)
		dp[0][i] = fight(idmap[i], S[0]);
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (fight(idmap[j], S[i]) < 0)
				continue;
			for (int k = 0; k < 3; k++)
			{
				if (j == k || dp[i - 1][k] < 0)
					continue;
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + fight(idmap[j], S[i]));
			}
		}
	}

	cout << *max_element(dp[N - 1].begin(), dp[N - 1].end()) << endl;

	return 0;
}
