#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; i++)
		cin >> H[i];
	
	vector<pair<int, int> > idx;
	for (int i = 0; i < N; i++)
		idx.emplace_back(H[i], i);

	sort(idx.begin(), idx.end());
	reverse(idx.begin(), idx.end());

	vector<int> deg(N + 1, 0);

	set<int> vis;
	vis.insert(-1);
	vis.insert(N);
	for (int i = 0; i < N; i++)
	{
		int x = idx[i].second;
		auto itr = vis.lower_bound(x);
		int r = *itr;
		--itr;
		int l = *itr + 1;
		if (l > 0)
			l--;
		if (r < N)
			r++;
		// cerr << x << ": " << l << "->" << r << endl;
		deg[l]++;
		deg[x]--;
		// deg[x + 1]++;
		// deg[r]--;
		vis.insert(x);
	}

	int z = 0;
	vector<int> ans(N);
	for (int i = 0; i < N; i++)
	{
		z += deg[i];
		ans[i] = z;
	}

	for (int i = 0; i < N; i++)
	{
		if (i > 0)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	return 0;
}
