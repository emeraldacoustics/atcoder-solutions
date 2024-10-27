#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int mod = 998244353;

template <class T>
inline int remainder(const T & x)
{
	if (x < 0)
		return x + mod;
	else if (x < mod)
		return x;
	else
		return x - mod;
}

int main()
{
	ios::sync_with_stdio(false);

	int N, M, K;
	cin >> N >> M >> K;
	vector<int> X(M), Y(M);
	for (int i = 0; i < M; i++)
	{
		cin >> X[i] >> Y[i];
		X[i]--;
		Y[i]--;
	}

	vector<pair<int, int> > edges;
	for (int i = 0; i < M; i++)
		edges.emplace_back((Y[i] - 1 + N) % N, X[i]);
	sort(edges.begin(), edges.end());

	vector<int> dp(N, 0);
	dp[0] = 1;
	for (int k = 0; k < K; k++)
	{

		vector<pair<int, int> > dpv;
		for (int i = 0, j = i; i < edges.size(); i = j)
		{
			int v = edges[i].first;
			int x = dp[v];
			for (; j < edges.size() && edges[i].first == edges[j].first; j++)
				x = remainder(x + dp[edges[j].second]);

			dpv.emplace_back(v, x);
		}
		for (const auto & p : dpv)
			dp[p.first] = p.second;

		for (int i = 0; i < edges.size(); i++)
		{
			edges[i].first = (edges[i].first - 1 + N) % N;
			edges[i].second = (edges[i].second - 1 + N) % N;
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
		ans = remainder(ans + dp[i]);
	
	cout << ans << endl;

	return 0;
}
