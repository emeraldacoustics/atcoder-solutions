#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int Y;

	cin >> Y;

	if (Y % 4 ||
		Y % 400 && Y % 100 == 0)
		cout << 365;
	else
		cout << 366;
	cout << endl;

	return 0;
}
