#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	vector<int> L;
	vector<pair<int, int> > F(N + 1);
	F[0] = make_pair(0, -1);
	for (int i = 0; i < N; i++)
	{
		auto itr = lower_bound(L.begin(), L.end(), A[i]);
		if (itr == L.end())
			L.push_back(A[i]);
		else
			*itr = A[i];

		F[i + 1] = make_pair(L.size(), L.back());
	}

	int ans = L.size();

	L.clear();
	for (int i = N - 1; i >= 0; i--)
	{
		auto itr = upper_bound(L.begin(), L.end(), F[i].second + 2, greater<int>());
		if (itr == L.begin())
			ans = max(ans, F[i].first + 1);
		else
			ans = max(ans, F[i].first + int(itr - L.begin()) + 1);

		itr = lower_bound(L.begin(), L.end(), A[i], greater<int>());
		if (itr == L.end())
			L.push_back(A[i]);
		else
			*itr = A[i];
	}

	cout << ans << endl;

	return 0;
}
