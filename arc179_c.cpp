#include <iostream>
#include <vector>

using namespace std;

int add(int l, int r)
{
	cout << "+ " << l + 1 << " " << r + 1 << endl;
	cout.flush();

	int P;
	cin >> P;
	if (P > 0)
		P--;

	return P;
}

int compare(int l, int r)
{
	cout << "? " << l + 1 << " " << r + 1 << endl;
	cout.flush();

	int Q;
	cin >> Q;

	return Q;
}

void done()
{
	cout << "!" << endl;
	cout.flush();
}

vector<int> sort_indexes(const vector<int> idx)
{
	if (idx.size() <= 1)
		return idx;
	
	vector<int> lv, rv;
	for (int i = 0; i < idx.size() / 2; i++)
		lv.push_back(idx[i]);
	for (int i = idx.size() / 2; i < idx.size(); i++)
		rv.push_back(idx[i]);

	lv = sort_indexes(lv);
	rv = sort_indexes(rv);

	vector<int> ans;
	for (int l = 0, r = 0; l < lv.size() || r < rv.size(); )
	{
		if (l == lv.size())
			ans.push_back(rv[r++]);
		else if (r == rv.size())
			ans.push_back(lv[l++]);
		else
		{
			int q = compare(rv[r], lv[l]);
			if (q)
				ans.push_back(rv[r++]);
			else
				ans.push_back(lv[l++]);
		}
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vector<int> idx;
	for (int i = 0; i < N; i++)
		idx.push_back(i);
	
	idx = sort_indexes(idx);
	for (; idx.size() > 1; )
	{
		const int n = idx.size();
		int p = add(idx[0], idx[n - 1]);

		vector<int> nxt;
		int l = 0, h = n - 1;
		if (n > 2)
		{
			for (; l + 1 < h; )
			{
				int m = l + (h - l) / 2;
				if (compare(p, idx[m]))
					h = m;
				else
					l = m;
			}
		}
		for (int i = 1; i < h && i < n - 1; i++)
			nxt.push_back(idx[i]);
		nxt.push_back(p);
		for (int i = h; i < n - 1; i++)
			nxt.push_back(idx[i]);

		idx = nxt;
	}

	done();

	return 0;
}
