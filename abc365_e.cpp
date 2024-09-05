#include <iostream>
#include <vector>

using namespace std;

const int bitlvl = 27;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	long long ans = 0;
	for (int bit = 0; bit < bitlvl; bit++)
	{
		vector<int> acc(N + 1, 0);
		for (int i = 0; i < N; i++)
			acc[i + 1] = acc[i] ^ (A[i] >> bit & 1);
		vector<vector<int> > dp(2, vector<int>(N + 1, 0));
		for (int i = 0; i < N; i++)
		{
			dp[0][i + 1] = dp[0][i] + !acc[i + 1];
			dp[1][i + 1] = dp[1][i] + acc[i + 1];
		}
		
		for (int i = 0; i < N - 1; i++)
		{
			int b = (A[i] >> bit & 1) ^ acc[i + 1];
			ans += (1ll << bit) * (dp[b ^ 1][N] - dp[b ^ 1][i + 1]);
		}
	}

	cout << ans << endl;

	return 0;
}
