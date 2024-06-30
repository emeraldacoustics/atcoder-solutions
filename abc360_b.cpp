#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solve(const string & S, const string & T)
{
	for (int w = 1; w < S.length(); w++)
	{
		for (int c = 0; c < w; c++)
		{
			string s;
			for (int k = c; k < S.length(); k += w)
				s.push_back(S[k]);
			
			if (s == T)
				return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);

	string S, T;
	cin >> S >> T;

	cout << (solve(S, T) ? "Yes" : "No") << endl;

	return 0;
}
