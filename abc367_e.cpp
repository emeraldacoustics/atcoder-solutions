#include <iostream>
#include <vector>

using namespace std;

vector<int> get_pow(vector<int> b, long long e)
{
	const int n = b.size();
	vector<int> ans(n);
	for (int i = 0; i < n; i++)
		ans[i] = i;
	for (; e > 0; e >>= 1)
	{
		if (e & 1)
		{
			vector<int> nxt(n);
			for (int i = 0; i < n; i++)
				nxt[i] = ans[b[i]];
			ans = nxt;
		}
		vector<int> nxt(n);
		for (int i = 0; i < n; i++)
			nxt[i] = b[b[i]];
		b = nxt;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);

	int N;
	long long K;
	cin >> N >> K;
	vector<int> X(N);
	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
		X[i]--;
	}
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];

	vector<int> Z = get_pow(X, K);
	for (int i = 0; i < N; i++)
	{
		if (i > 0)
			cout << " ";
		cout << A[Z[i]];
	}
	cout << endl;

	return 0;
}
