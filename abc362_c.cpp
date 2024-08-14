#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> L(N), R(N);
	for (int i = 0; i < N; i++)
		cin >> L[i] >> R[i];
	
	long long l = accumulate(L.begin(), L.end(), 0ll);
	long long r = accumulate(R.begin(), R.end(), 0ll);

	if (l <= 0 && 0 <= r)
	{
		cout << "Yes" << endl;
		
		long long s = -l;
		for (int i = 0; i < N; i++)
		{
			int d = min<long long>(R[i] - L[i], s);
			s -= d;

			if (i > 0)
				cout << " ";
			cout << L[i] + d;
		}
		cout << endl;
	}
	else
		cout << "No" << endl;

	return 0;
}
