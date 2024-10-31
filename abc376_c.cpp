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
	vector<int> B(N - 1);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N - 1; i++)
		cin >> B[i];
	

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	bool vld = true;
	for (int i = 0; i < N - 1; i++)
	{
		if (A[i] > B[i])
		{
			vld = false;
			break;
		}
	}

	if (vld)
	{
		int ans = A[0];
		for (int i = N - 1; i > 0; i--)
		{
			if (A[i] > B[i - 1])
			{
				ans = A[i];
				break;
			}
		}

		cout << ans;
	}
	else
		cout << "-1";
	cout << endl;

	return 0;
}
