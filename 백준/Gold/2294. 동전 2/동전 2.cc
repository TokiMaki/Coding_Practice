#include <iostream>
#include <vector>

using namespace std;

vector<int> coin;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> dp(k + 1);
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}

	fill_n(dp.begin(), k + 1, -1);
	dp[0] = 0;

	for (int i : coin)
	{
		for (int j = 0; j < k; ++j)
		{
			if (i + j <= k) {
				if (dp[i + j] != -1 && dp[j] != -1)
					dp[i + j] = min(dp[i + j], dp[j] + 1);
				else if (dp[j] != -1) {
					dp[i + j] = dp[j] + 1;
				}
			}
		}
	}

	cout << dp[k];
}