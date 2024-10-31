#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, C;
	cin >> N >> C;
	vector<int> T(N);
	for (int i = 0; i < N; i++)
		cin >> T[i];

	int ans = 0;
	int prv = T[0] - C;
	for (int i = 0; i < N; i++)
	{
		if (prv + C <= T[i])
		{
			ans++;
			prv = T[i];
		}
	}

	cout << ans << endl;

	return 0;
}
