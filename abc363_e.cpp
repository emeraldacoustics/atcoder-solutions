#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int main()
{
	ios::sync_with_stdio(false);

	int H, W, Y;
	cin >> H >> W >> Y;
	vector<vector<int> > A(H, vector<int>(W));
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			cin >> A[i][j];
	}

	priority_queue<pair<int, pair<int, int> > > que;
	vector<vector<bool> > vis(H, vector<bool>(W, false));
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (i == 0 || i == H - 1 || j == 0 || j == W - 1)
			{
				que.emplace(-A[i][j], make_pair(i, j));
				vis[i][j] = true;
			}
		}
	}

	const auto is_inside = [&](const pair<int, int> & p)
	{
		return 0 <= p.first && p.first < H && 0 <= p.second && p.second < W;
	};

	int ans = H * W;
	for (int y = 1; y <= Y; y++)
	{
		for (; !que.empty() && que.top().first >= -y; ans--)
		{
			pair<int, int> u = que.top().second;
			que.pop();

			for (int i = 0; i < 4; i++)
			{
				pair<int, int> v = make_pair(u.first + dr[i], u.second + dc[i]);
				if (is_inside(v) && !vis[v.first][v.second])
				{
					vis[v.first][v.second] = true;
					que.emplace(-A[v.first][v.second], v);
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}
