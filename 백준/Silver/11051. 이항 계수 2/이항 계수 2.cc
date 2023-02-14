#include <iostream>

using namespace std;

long long bino_coef_dp(int n, int r) {
	static long long dp[1001][1001] = { 0, };
	if (r > n)
		return 0;
	if (dp[n][r] > 0)
		return dp[n][r];
	if (r == 0 || r == n)
		return dp[n][r] = 1;
	return dp[n][r] = (bino_coef_dp(n - 1, r - 1) + bino_coef_dp(n - 1, r)) % 10007;
}


int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	
	cout << bino_coef_dp(N, K);
}