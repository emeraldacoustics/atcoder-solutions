#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> A(N);
	vector<int> W(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> W[i];

	vector<vector<int> > Wv(N);
	for (int i = 0; i < N; i++)
		Wv[A[i] - 1].push_back(W[i]);

	int ans = 0;
	for (const auto & v : Wv)
	{
		if (!v.empty())
			ans += accumulate(v.begin(), v.end(), 0) - *max_element(v.begin(), v.end());
	}

	cout << ans << endl;

	return 0;
}
