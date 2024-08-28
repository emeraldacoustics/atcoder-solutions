#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int R;
	cin >> R;

	cout << (100 - R % 100) << endl;

	return 0;
}
