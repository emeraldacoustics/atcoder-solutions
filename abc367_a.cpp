#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int A, B, C;
	cin >> A >> B >> C;

	if (B > C)
		C += 24;

	bool ans = true;
	for (int i = 0; i < 2; i++)
	{
		if (B < A && A < C)
		{
			ans = false;
			break;
		}
		A += 24;
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}
