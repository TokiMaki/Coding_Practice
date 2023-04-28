#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int dp[10001];
int memorybyte[101];
int c[101];

int main()
{
	int N, M;
	int sum = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		cin >> memorybyte[i];
	}
	for (int i = 1; i <= N; ++i)
	{
		cin >> c[i];
		sum += c[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = sum; j >= 1; --j)
		{
			if (c[i] <= j)
			{
				dp[j] = max(dp[j], dp[j - c[i]] + memorybyte[i]);
			}
		}
	}
	for(int i = 0; i <= sum; ++i)
	{
		if (dp[i] >= M) {
			cout << i;
			break;
		}
	}
}