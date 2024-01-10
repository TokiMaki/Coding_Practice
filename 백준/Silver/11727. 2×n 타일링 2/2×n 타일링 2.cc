#include <iostream>

using namespace std;

long long dp[1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; ++i)
	{
		dp[i] = ((dp[i - 1] % 10007) + ((2 * dp[i - 2]) % 10007)) % 10007;
	}

	cout << dp[n];
}