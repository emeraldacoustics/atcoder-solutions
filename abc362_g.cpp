#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class SuffixAutomaton
{
public:
	static const int sigma = 26;

	class Node
	{
	public:
		int len;
		int slnk;
		int son[sigma];
		int cnt;
		bool cloned;

		Node(void) : len(0), slnk(-1), cnt(0), cloned(false)
		{
			memset(son, 0, sizeof son);
		}
	};

	int sz, cur;
	vector<Node> nodes;

	int idx(const T & c)
	{
		return c - 'a';
	}

	SuffixAutomaton(void)
	{
		clear();
	}

	Node & operator [] (const int & x)
	{
		return nodes[x];
	}

	void clear(void)
	{
		sz = cur = 0;
		nodes.clear();
		add_node();
	}

	int add_node(void)
	{
		nodes.push_back(Node());
		return sz++;
	}

	Node clone(const Node & node)
	{
		Node ans;
		ans.len = node.len;
		ans.slnk = node.slnk;
		memcpy(ans.son, node.son, sizeof ans.son);
		ans.cloned = true;
		return ans;
	}

	int extend(const int & c)
	{
		int last = cur;
		bool flg = nodes[last].son[c];
		if (!flg)
		{
			cur = add_node();
			nodes[cur].len = nodes[last].len + 1;
		}
		else
			cur = nodes[last].son[c];
		int p = last;
		for (; p != -1 && !nodes[p].son[c]; p = nodes[p].slnk)
			nodes[p].son[c] = cur;
		if (p == -1)
			nodes[cur].slnk = 0;
		else
		{
			int q = nodes[p].son[c];
			if (nodes[p].len + 1 == nodes[q].len)
			{
				if (!flg)
					nodes[cur].slnk = q;
			}
			else
			{
				int r = add_node();
				nodes[r] = clone(nodes[q]);
				nodes[r].len = nodes[p].len + 1;
				nodes[q].slnk = nodes[cur].slnk = r;
				for (; p != -1 && nodes[p].son[c] == q; p = nodes[p].slnk)
					nodes[p].son[c] = r;
				if (flg)
					cur = r;
			}
		}
		return cur;
	}

	void build(const T * first, const T * last)
	{
		const T * & s = first;
		const int n = last - first;

		clear();
		for (int i = 0; i < n; i++)
			extend(idx(s[i]));
	}

	vector<int> sorted_indices(void)
	{
		int mxlen = 0;
		for (int u = 0; u < sz; u++)
			mxlen = max(mxlen, nodes[u].len);
		vector<int> occ(mxlen + 1);
		for (int u = 0; u < sz; u++)
			occ[nodes[u].len]++;
		for (int i = 1; i <= mxlen; i++)
			occ[i] += occ[i - 1];
		vector<int> ans(sz);
		for (int u = 0; u < sz; u++)
			ans[--occ[nodes[u].len]] = u;
		return ans;
	}

	vector<int> sorted_indices(const vector<int> & qry)
	{
		int mxlen = 0;
		for (const auto & u : qry)
			mxlen = max(mxlen, nodes[u].len);
		vector<int> occ(mxlen + 1);
		for (const auto & u : qry)
			occ[nodes[u].len]++;
		for (int i = 1; i <= mxlen; i++)
			occ[i] += occ[i - 1];
		vector<int> ans(qry.size());
		for (const auto & u : qry)
			ans[--occ[nodes[u].len]] = u;
		return ans;
	}
};

int main()
{
	ios::sync_with_stdio(false);

	string S;
	cin >> S;

	SuffixAutomaton<char> sa;
	sa.clear();
	for (int i = 0; i < S.length(); i++)
		sa.extend(sa.idx(S[i]));
	
	for (int i = 0; i < sa.sz; i++)
		sa[i].cnt = !sa[i].cloned;
	vector<int> idx = sa.sorted_indices();
	for (int i = idx.size() - 1; i >= 0; i--)
	{
		const int u = idx[i];
		if (sa[u].slnk >= 0)
			sa[sa[u].slnk].cnt += sa[u].cnt;
	}

	int Q;
	cin >> Q;
	for (int QN = 0; QN < Q; QN++)
	{
		string T;
		cin >> T;

		int u = 0;
		for (int i = 0; i < T.length(); i++)
		{
			u = sa[u].son[sa.idx(T[i])];
			if (u == 0)
			{
				u = -1;
				break;
			}
		}

		cout << (u < 0 ? 0 : sa[u].cnt) << endl;
	}

	return 0;
}
