#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int R, G, B;
	cin >> R >> G >> B;
	
	string C;
	cin >> C;

	int ans = 0;
	if (C[0] == 'R')
		ans = min(G, B);
	else if (C[0] == 'G')
		ans = min(R, B);
	else if (C[0] == 'B')
		ans = min(R, G);

	cout << ans << endl;

	return 0;
}
