#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N;
    string T, A;

    cin >> N;
    cin >> T >> A;

    bool ans = false;
    for (int i = 0; i < N; i++)
    {
        if (T[i] == 'o' && A[i] == 'o')
        {
            ans = true;
            break;
        }
    }

    cout << (ans ? "Yes" : "No") << endl;

	return 0;
}
