#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	int answer = 0;

	cin >> N;

	vector<int> A(N);
	vector<int> dp(N);
	vector<int> rdp(N);


	for(int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	dp[0] = 1;
	rdp[N - 1] = 1;

	for(int i = 1; i < N; ++i)
	{
		dp[i] = 1;
		for(int j = i - 1; j >= 0; --j)
		{
			if (A[i] > A[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = N - 2; i >= 0; --i)
	{
		rdp[i] = 1;
		for (int j = i + 1; j < N; ++j)
		{
			if (A[i] > A[j])
			{
				rdp[i] = max(rdp[i], rdp[j] + 1);
			}
		}
	}
	for(int i = 0; i < N; ++i)
	{
		answer = max(answer, dp[i] + rdp[i] - 1);
	}
	cout << answer;
}