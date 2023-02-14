#include <iostream>

using namespace std;

long long bino_coef_dp(int n, int r) {
	static long long dp[30][30] = { 0, };
	if (r > n)
		return 0;
	if (dp[n][r] > 0)
		return dp[n][r];
	if (r == 0 || n == r)
		return dp[n][r] = 1;
	return dp[n][r] = bino_coef_dp(n - 1, r) + bino_coef_dp(n - 1, r - 1);
}

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; ++i) {
		int N, M;
		cin >> N >> M;

		cout << bino_coef_dp(M, N) << "\n";
	}
}