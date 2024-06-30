#include <iostream>

using namespace std;

const int mod = 998244353;

template <class T, class U>
inline T pow_mod(T b, U e)
{
	T ans = 1;
	for (; e > 0; e >>= 1)
	{
		if (e & 1)
			ans = (long long)ans * b % mod;
		b = (long long)b * b % mod;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);

	int N, K;
	cin >> N >> K;

	int R = pow_mod(N, mod - 2);
	int ans = 1;
	for (int i = 0; i < K; i++)
		ans = ((long long)ans * (N - 2) + (N + 1)) % mod * R % mod;
	
	cout << ans << endl;

	return 0;
}
