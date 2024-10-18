#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	int prm = accumulate(A.begin(), A.end(), 0ll) % M;
	vector<int> X(N + 1), Y(N + 1);
	X[0] = 0;
	Y[0] = prm;
	for (int i = 0; i < N; i++)
	{
		X[i + 1] = (X[i] + A[i]) % M;
		Y[i + 1] = (Y[i] + A[i]) % M;
	}

	vector<int> prv(M, 0), nxt(M, 0);
	for (int i = 0; i < N; i++)
		nxt[X[i]]++;
	
	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		nxt[X[i]]--;
		ans += prv[X[i]] + nxt[X[i]];
		prv[Y[i]]++;
	}

	cout << ans << endl;

	return 0;
}
