#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, T;
	cin >> N >> T;
	string S;
	cin >> S;
	vector<int> X(N);
	for (int i = 0; i < N; i++)
		cin >> X[i];
	
	vector<int> Z[2];
	for (int i = 0; i < N; i++)
		Z[S[i] - '0'].push_back(X[i]);
	
	for (int i = 0; i < 2; i++)
		sort(Z[i].begin(), Z[i].end());

	long long ans = 0;
	for (int i = 0, l = 0, r = 0; i < Z[0].size(); i++)
	{
		for (; l < Z[1].size() && Z[1][l] + T < Z[0][i] - T; l++);
		for (; r < Z[1].size() && Z[1][r] < Z[0][i]; r++);

		ans += r - l;
	}

	cout << ans << endl;

	return 0;
}
