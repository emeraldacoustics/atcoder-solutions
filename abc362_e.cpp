#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int mod = 998244353;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	vector<int> dv;
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
			dv.push_back(A[j] - A[i]);
	}

	sort(dv.begin(), dv.end());
	dv.resize(unique(dv.begin(), dv.end()) - dv.begin());
	vector<int> ans(N + 1, 0);
	ans[1] = N;
	for (const auto & d : dv)
	{
		vector<vector<int> > dp(N + 1, vector<int>(N + 1, 0));

		dp[0][0] = 1;
		for (int i = 0; i < N; i++)
		{
			for (int k = 0; k < N; k++)
			{
				for (int j = 0; j <= i; j++)
				{
					if (j == 0 && k == 0 || (j > 0 && A[i] - A[j - 1] == d))
						dp[i + 1][k + 1] = (dp[i + 1][k + 1] + dp[j][k]) % mod;
				}
			}
		}

		for (int i = 2; i <= N; i++)
		{
			for (int j = i; j <= N; j++)
				ans[i] = (ans[i] + dp[j][i]) % mod;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (i > 1)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	return 0;
}
