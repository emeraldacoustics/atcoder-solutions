#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	string S;

	cin >> S;

	int R = find(S.begin(), S.end(), 'R') - S.begin();
	int M = find(S.begin(), S.end(), 'M') - S.begin();

	cout << (R < M ? "Yes" : "No") << endl;

	return 0;
}
