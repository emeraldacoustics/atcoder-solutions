#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<vector<int> > E(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		a--, b--;
		E[a].push_back(b);
	}

	vector<int> prv(N, -1);
	queue<int> que;
	for (que.push(0); !que.empty(); que.pop())
	{
		const int u = que.front();
		for (const int & v : E[u])
		{
			if (prv[v] < 0)
			{
				que.push(v);
				prv[v] = u;
			}
		}
	}

	if (prv[0] < 0)
		cout << "-1";
	else
	{
		int ans = 0;
		int u = 0;
		do
		{
			ans++;
			u = prv[u];
		} while (u != 0);
		
		cout << ans;
	}
	cout << endl;

	return 0;
}
