#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	long long M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	long long sum = accumulate(A.begin(), A.end(), 0ll);

	if (sum <= M)
		cout << "infinite";
	else
	{
		A.push_back(0);
		sort(A.begin(), A.end());
		int ans;
		for (int i = N - 1; i >= 0; i--)
		{
			sum -= A[i + 1];
			if (sum <= M)
			{
				int x = (M - sum) / (N - i);
				if (x >= A[i])
				{
					ans = x;
					break;
				}
			}
		}
		cout << ans;
	}
	cout << endl;

	return 0;
}
