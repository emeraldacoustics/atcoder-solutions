#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, X, Y;
	cin >> N >> X >> Y;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i];
	
	vector<vector<int> > dp(N + 1, vector<int>(X + 1, -1));
	dp[0][0] = 0;
	for (int k = 0; k < N; k++)
	{
		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j <= X; j++)
			{
				if (dp[i][j] < 0)
					continue;

				if (X < j + A[k] || Y < dp[i][j] + B[k])
					continue;

				if (dp[i + 1][j + A[k]] < 0 || dp[i + 1][j + A[k]] > dp[i][j] + B[k])
					dp[i + 1][j + A[k]] = dp[i][j] + B[k];
			}
		}
	}

	int ans = 0;
	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; j < dp[i].size(); j++)
		{
			if (dp[i][j] >= 0)
				ans = max(ans, i);
		}
	}
	if (ans < N)
		ans++;

	cout << ans << endl;

	return 0;
}
