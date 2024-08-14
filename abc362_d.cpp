#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const long long inf = 0x7f7f7f7f7f7f7f7fll;

template <class T>
class Dijkstra
{
public:
	static const int maxn = 200000;

	class Edge
	{
	public:
		int u, v;
		T w;

		Edge(void) : u(0), v(0), w(0)
		{

		}

		Edge(const int & u, const int & v, const T & w) : u(u), v(v), w(w)
		{

		}
	};

	class Node
	{
	public:
		int u;
		T d;

		Node(void) : u(0), d(0)
		{

		}

		Node(const int & u, const T & d) : u(u), d(d)
		{

		}

		bool operator < (const Node & rhs) const
		{
			return d > rhs.d;
		}
	};

	int n;
	vector<Edge> E[maxn];
	T d[maxn];

	Dijkstra(void)
	{

	}

	void resize(const int & n)
	{
		for (int i = 0; i < this->n; i++)
			E[i].clear();
		this->n = n;
	}

	void add_edge(const int & u, const int & v, const T & w)
	{
		E[u].emplace_back(u, v, w);
	}

	void dijkstra(const int & s)
	{
		vector<int> vec(1, s);
		dijkstra(vec);
	}

	void dijkstra(const vector<int> & s)
	{
		memset(d, inf, sizeof d[0] * n);
		priority_queue<Node> que;
		for (const auto & x : s)
		{
			d[x] = 0;
			que.emplace(x, 0);
		}
		for (; !que.empty(); )
		{
			Node node = que.top();
			int u = node.u;
			que.pop();
			if (node.d > d[u])
				continue;
			for (const auto & edge : E[u])
			{
				int v = edge.v;
				T w = edge.w;
				if (d[v] > d[u] + w)
				{
					d[v] = d[u] + w;
					que.emplace(v, d[v]);
				}
			}
		}
	}
};

Dijkstra<long long> Dij;

int main()
{
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	
	Dij.resize(N);
	for (int i = 0; i < M; i++)
	{
		int U, V, B;
		cin >> U >> V >> B;
		U--;
		V--;

		Dij.add_edge(U, V, B + A[V]);
		Dij.add_edge(V, U, B + A[U]);
	}

	Dij.dijkstra(0);

	for (int i = 1; i < N; i++)
	{
		if (i > 1)
			cout << " ";
		cout << Dij.d[i] + A[0];
	}
	cout << endl;

	return 0;
}
