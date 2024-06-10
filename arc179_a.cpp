#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;
	vector<long long> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	long long sum = accumulate(A.begin(), A.end(), 0ll);

	if (0 > sum && 0 >= K && K > sum)
		cout << "No" << endl;
	else
	{
		vector<int> X;
		if (sum >= K)
		{
			for (int i = 0; i < N; i++)
			{
				if (A[i] >= 0)
					X.push_back(A[i]);
			}
			for (int i = 0; i < N; i++)
			{
				if (A[i] < 0)
					X.push_back(A[i]);
			}
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				if (A[i] < 0)
					X.push_back(A[i]);
			}
			for (int i = 0; i < N; i++)
			{
				if (A[i] >= 0)
					X.push_back(A[i]);
			}
		}

		cout << "Yes" << endl;
		for (int i = 0; i < N; i++)
		{
			if (i > 0)
				cout << " ";
			cout << X[i];
		}
		cout << endl;
	}

	return 0;
}
