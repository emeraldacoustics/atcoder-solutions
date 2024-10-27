#include <iostream>
#include <string>

using namespace std;

int count_abc(const string & s)
{
	int ans = 0;
	for (int i = 0; i + 3 <= s.length(); i++)
	{
		if (s[i] == 'A' &&
			s[i + 1] == 'B' &&
			s[i + 2] == 'C')
			ans++;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);

	int N, Q;
	cin >> N >> Q;
	string S;
	cin >> S;

	int cnt = count_abc(S);

	for (int QN = 0; QN < Q; QN++)
	{
		int X;
		char C;
		cin >> X >> C;
		X--;

		int l = max(0, X - 2);
		int r = min<int>(S.length(), X + 3);
		
		cnt -= count_abc(S.substr(l, r - l));
		S[X] = C;
		cnt += count_abc(S.substr(l, r - l));

		cout << cnt << endl;
	}

	return 0;
}
