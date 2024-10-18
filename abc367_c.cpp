#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	vector<int> R(N);
	for (int i = 0; i < N; i++)
		cin >> R[i];
	
	int X = 1;
	for (const auto & r : R)
		X *= r;
	
	for (int x = 0; x < X; x++)
	{
		int z = x;
		vector<int> A(N);
		for (int i = N - 1; i >= 0; i--)
		{
			A[i] = z % R[i] + 1;
			z /= R[i];
		}
		if (accumulate(A.begin(), A.end(), 0) % K == 0)
		{
			for (int i = 0; i < N; i++)
			{
				if (i > 0)
					cout << " ";
				cout << A[i];
			}
			cout << endl;
		}
	}

	return 0;
}
