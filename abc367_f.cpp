#include <iostream>
#include <random>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		A[i]--;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
		B[i]--;
	}

	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<long long> distrib(1ll, 1000000000000ll);
	vector<long long> Z(N);
	for (int i = 0; i < N; i++)
		Z[i] = distrib(gen);

	vector<long long> X(N + 1), Y(N + 1);
	X[0] = 0;
	Y[0] = 0;
	for (int i = 0; i < N; i++)
	{
		X[i + 1] = X[i] + Z[A[i]];
		Y[i + 1] = Y[i] + Z[B[i]];
	}

	for (int QN = 0; QN < Q; QN++)
	{
		int l, r, L, R;
		cin >> l >> r >> L >> R;
		l--, L--;

		if (r - l == R - L && X[r] - X[l] == Y[R] - Y[L])
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}

	return 0;
}
