#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class DisjointSetsUnion
{
public:
	int n;
	vector<int> p;

	DisjointSetsUnion(void) : n(0)
	{

	}

	void resize(const int & n)
	{
		this->n = n;
		p.clear();
		p.resize(n, -1);
	}

	int root(const int & u)
	{
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}

	bool union_sets(const int & u, const int & v)
	{
		int ur = root(u), vr = root(v);
		if (ur == vr)
			return false;
		else
		{
			if (p[ur] > p[vr])
				swap(ur, vr);
			p[ur] += p[vr];
			p[vr] = ur;
			return true;
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	vector<pair<int, pair<int, int> > > E(Q);
	for (int i = 0; i < Q; i++)
	{
		cin >> E[i].second.first >> E[i].second.second >> E[i].first;
		E[i].second.first--;
		E[i].second.second--;
	}

	set<int> s;
	for (int i = 0; i < N - 1; i++)
		s.insert(i);

	long long ans = 0;
	for (int i = 0; i < Q; i++)
		ans += E[i].first;

	sort(E.begin(), E.end());
	DisjointSetsUnion dsu;
	dsu.resize(N);
	for (int q = 0; q < Q; q++)
	{
		auto itr = s.lower_bound(E[q].second.first);
		for (; itr != s.end() && *itr < E[q].second.second; )
		{
			auto ktr = itr++;
			const int u = *ktr, v = u + 1;
			s.erase(ktr);
			if (dsu.union_sets(u, v))
				ans += E[q].first;
		}
	}

	int cnt = 0;
	for (const auto & p : dsu.p)
	{
		if (p < 0)
			cnt++;
	}
	if (cnt > 1)
		cout << "-1";
	else
		cout << ans;
	cout << endl;

	return 0;
}
