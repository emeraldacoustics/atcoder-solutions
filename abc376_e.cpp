#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int TN = 0; TN < T; TN++)
	{
		int N, K;
		cin >> N >> K;
		vector<int> A(N), B(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		for (int i = 0; i < N; i++)
			cin >> B[i];
		
		vector<int> idx(N);
		for (int i = 0; i < N; i++)
			idx[i] = i;
		sort(idx.begin(), idx.end(), [&](const int & lhs, const int & rhs)
		{
			return A[lhs] < A[rhs];
		});

		priority_queue<int> que;
		long long sum = 0;
		for (int i = 0; i < K - 1; i++)
		{
			que.push(B[idx[i]]);
			sum += B[idx[i]];
		}

		long long ans = -1;
		for (int i = K - 1; i < N; i++)
		{
			const int a = A[idx[i]], b = B[idx[i]];
			long long val = a * (sum + b);

			if (ans < 0 || ans > val)
				ans = val;
			
			if (!que.empty() && que.top() > b)
			{
				sum -= que.top();
				que.pop();
				sum += b;
				que.push(b);
			}
		}

		cout << ans << endl;
	}

	return 0;
}
