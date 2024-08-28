#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, T, P;
	cin >> N >> T >> P;
	vector<int> L(N);
	for (int i = 0; i < N; i++)
		cin >> L[i];
	
	sort(L.begin(), L.end());

	cout << max(0, T - L[N - P]) << endl;

	return 0;
}
