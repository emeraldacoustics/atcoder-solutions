#include <iostream>
#include <vector>

using namespace std;

const int mod = 998244353;

int main()
{
	ios::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;
	vector<int> X(M);
	for (int i = 0; i < M; i++)
	{
		cin >> X[i];
		X[i]--;
	}

	vector<int> bit(M, 0);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == X[j])
				bit[i] |= 1 << j;
		}
	}

	vector<vector<int> > dp(2, vector<int>(1 << M, 0));
	dp[0][(1 << M) - 1] = 1;
	int cur = 0, nxt = 1;
	for (int i = 0; i < N; i++)
	{
		for (int x = 0; x < M; x++)
		{
			for (int s = 0; s < 1 << M; s++)
			{
				if (s & (1 << x))
				{
					int t = s & ~(1 << x) | bit[x];
					dp[nxt][t] = (dp[nxt][t] + dp[cur][s]) % mod;
				}
			}
		}
		fill(dp[cur].begin(), dp[cur].end(), 0);
		swap(cur, nxt);
	}

	int ans = 0;
	for (int s = 0; s < 1 << M; s++)
		ans = (ans + dp[cur][s]) % mod;
	
	cout << ans << endl;

	return 0;
}
