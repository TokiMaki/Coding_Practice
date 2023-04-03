#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	vector<int> coins(n);
	vector<int> dp(k + 1);

	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
	}
	dp[0] = 1;
	for (int j = 0; j < n; ++j) {
		for (int i = coins[j]; i <= k; ++i) {
				dp[i] = dp[i] + dp[i - coins[j]];
		}
	}

	cout << dp[k] << endl;
}