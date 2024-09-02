#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	long long X, Y;
	cin >> N >> X >> Y;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];

	int ans = N;
	long long Z = 0;

	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	Z = 0;
	for (int i = 0; i < N; i++)
	{
		Z += A[i];
		if (Z > X)
		{
			ans = min(ans, i + 1);
			break;
		}
	}

	sort(B.begin(), B.end());
	reverse(B.begin(), B.end());
	Z = 0;
	for (int i = 0; i < N; i++)
	{
		Z += B[i];
		if (Z > Y)
		{
			ans = min(ans, i + 1);
			break;
		}
	}

	cout << ans << endl;

	return 0;
}
