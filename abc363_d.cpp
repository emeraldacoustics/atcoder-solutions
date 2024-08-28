#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string solve(long long N)
{
	for (int len = 1; ; len++)
	{
		long long L = len == 1 ? 10 : 9;
		int hlf = (len + 1) / 2;
		for (int i = 1; i < hlf; i++)
			L *= 10;
		if (N < L)
		{
			string s;
			for (int i = 0; i < hlf; i++)
			{
				s.push_back('0' + N % 10);
				N /= 10;
			}
			if (len > 1)
				s.back()++;

			reverse(s.begin(), s.end());
			string ans = s;
			for (int i = ans.length(); i < len; i++)
				ans.push_back(s[len - i - 1]);

			return ans;
		}
		else
			N -= L;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	long long N;
	cin >> N;

	cout << solve(N - 1) << endl;

	return 0;
}
