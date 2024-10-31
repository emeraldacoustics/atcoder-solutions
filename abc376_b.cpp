#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	
	vector<int> X = { 0, 1 };
	int ans = 0;
	for (int QN = 0; QN < Q; QN++)
	{
		char H;
		int T;
		cin >> H >> T;
		T--;

		int x = H == 'L' ? 0 : 1;
		int Z = T;
		if (Z < X[x])
			Z += N;

		bool flg = false;
		for (int i = 0; i < 2; i++)
		{
			int Y = X[x ^ 1] + N * i;
			if (X[x] <= Y && Y <= Z)
			{
				flg = true;
				break;
			}
		}
		if (flg)
			ans += (X[x] - T + N) % N;
		else
			ans += (T - X[x] + N) % N;

		X[x] = T;
	}

	cout << ans << endl;

	return 0;
}
