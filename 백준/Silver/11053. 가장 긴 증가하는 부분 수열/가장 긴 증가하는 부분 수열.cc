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


	for(int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	dp[0] = 1;
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
	answer = *max_element(dp.begin(), dp.end());
	cout << answer;
}