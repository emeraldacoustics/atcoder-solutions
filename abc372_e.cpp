#include <iostream>
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

	const int maxk = 10;

	int N, Q;
	cin >> N >> Q;

	vector<vector<int> > idx(N);
	for (int i = 0; i < N; i++)
		idx[i].push_back(i);

	DisjointSetsUnion DSU;
	DSU.resize(N);

	for (int QN = 0; QN < Q; QN++)
	{
		int cmd;
		cin >> cmd;

		if (cmd == 1)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			int ur = DSU.root(u);
			int vr = DSU.root(v);
			if (ur != vr)
			{
				vector<int> mrg;
				for (int i = 0, j = 0; mrg.size() < maxk && (i < idx[ur].size() || j < idx[vr].size()); )
				{
					if (i == idx[ur].size())
						mrg.push_back(idx[vr][j++]);
					else if (j == idx[vr].size())
						mrg.push_back(idx[ur][i++]);
					else if (idx[ur][i] > idx[vr][j])
						mrg.push_back(idx[ur][i++]);
					else
						mrg.push_back(idx[vr][j++]);
				}
				DSU.union_sets(u, v);
				int r = DSU.root(u);
				idx[r] = mrg;
			}
		}
		else
		{
			int v, k;
			cin >> v >> k;
			v--;

			int r = DSU.root(v);
			if (idx[r].size() < k)
				cout << "-1";
			else
				cout << idx[r][k - 1] + 1;
			cout << endl;
		}
	}

	return 0;
}
