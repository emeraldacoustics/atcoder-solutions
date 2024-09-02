#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];

	sort(a.begin(), a.end());
	for (int QN = 0; QN < Q; QN++)
	{
		int b, k;
		cin >> b >> k;

		int low = -1, high = max(abs(b - a[0]), abs(b - a.back()));
		for (; low + 1 < high; )
		{
			int mid = low + (high - low) / 2;
			if (upper_bound(a.begin(), a.end(), b + mid) - lower_bound(a.begin(), a.end(), b - mid) >= k)
				high = mid;
			else
				low = mid;
		}

		cout << high << endl;
	}

	return 0;
}
