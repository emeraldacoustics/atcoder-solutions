#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int Y, Z;
	char ch;
	cin >> Y >> ch >> Z;

	cout << Y;
	if (Z > 0)
	{
		cout << ".";
		int w = 3;
		for (; Z > 0 && Z % 10 == 0; Z /= 10, w--);
		cout.fill('0');
		cout.width(w);
		cout << Z;
	}
	cout << endl;

	return 0;
}
