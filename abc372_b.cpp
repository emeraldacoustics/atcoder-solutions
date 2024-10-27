#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int M;
	cin >> M;

	const int maxA = 10;
	vector<int> lvl(maxA + 1, 0);
	lvl[0] = 1;
	for (int i = 1; i < lvl.size(); i++)
		lvl[i] = lvl[i - 1] * 3;
	
	vector<int> ans;
	for (int l = maxA; l >= 0; l--)
	{
		for (; M >= lvl[l]; M -= lvl[l])
			ans.push_back(l);
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i > 0)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;

	return 0;
}
