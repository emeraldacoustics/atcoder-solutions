#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	string S;
	cin >> S;

	for (const auto & c : S)
	{
		if (c != '.')
			cout << c;
	}
	cout << endl;

	return 0;
}
