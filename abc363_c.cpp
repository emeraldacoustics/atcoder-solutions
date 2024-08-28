#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	string S;
	cin >> S;

	sort(S.begin(), S.end());
	int ans = 0;
	do
	{
		bool vld = true;
		for (int i = 0; i <= N - K; i++)
		{
			int k = 0;
			for (; k < K; k++)
			{
				if (S[i + k] != S[i + K - k - 1])
					break;
			}
			if (k == K)
			{
				vld = false;
				break;
			}
		}

		if (vld)
			ans++;
	} while (next_permutation(S.begin(), S.end()));

	cout << ans << endl;	

	return 0;
}
