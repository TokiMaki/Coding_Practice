#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, k;

	cin >> n >> k;
	vector<int> dp(k + 1);
	
	dp[0] = 1;
	for(int i = 0; i < n; ++i)
	{
		int coin;
		cin >> coin;
		for(int j = coin; j <= k; ++j)
		{
			dp[j] += dp[j - coin];
		}
	}

	cout << dp[k];
}