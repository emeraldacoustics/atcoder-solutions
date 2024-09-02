#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<string> S(N);
	for (int i = 0; i < N; i++)
		cin >> S[i];
	
	bool ans = true;
	for (int i = 1; i < N - 1; i++)
	{
		if (S[i - 1] == "sweet" && S[i] == "sweet")
		{
			ans = false;
			break;
		}
	}

	cout << (ans ? "Yes" : "No") << endl;

	return 0;
}
