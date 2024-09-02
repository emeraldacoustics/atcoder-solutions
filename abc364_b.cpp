#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int H, W;
	cin >> H >> W;
	int Si, Sj;
	cin >> Si >> Sj;
	Si--, Sj--;
	vector<string> C(H);
	for (int i = 0; i < H; i++)
		cin >> C[i];
	string X;
	cin >> X;

	int r = Si, c = Sj;
	for (const auto & z : X)
	{
		int x = r, y = c;
		if (z == 'L')
			y--;
		else if (z == 'R')
			y++;
		else if (z == 'U')
			x--;
		else if (z == 'D')
			x++;
		if (0 <= x && x < H && 0 <= y && y < W && C[x][y] == '.')
			r = x, c = y;
	}

	cout << r + 1 << " " << c + 1 << endl;

	return 0;
}
