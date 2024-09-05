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
	
	int x = max_element(A.begin(), A.end()) - A.begin();
	int ans = -1;
	for (int i = 0; i < N; i++)
	{
		if (i == x)
			continue;
		
		if (ans < 0 || A[ans] < A[i])
			ans = i;
	}

	cout << ans + 1 << endl;

	return 0;
}
