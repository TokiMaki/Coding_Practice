#include <iostream>
#include <queue>

using namespace std;

int sticker[2][100000];
int dp[2][100000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, n;
	cin >> T;

	while (T > 0)
	{
		int answer = 0;
		cin >> n;

		for (int i = 0; i < 2; ++i)
		{
			fill_n(dp[i], n, 0);
		}

		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n; ++j)
			{
				cin >> sticker[i][j];
			}
		}

		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = sticker[0][1] + dp[1][0];
		dp[1][1] = sticker[1][1] + dp[0][0];

		for (int i = 0; i < n; ++i)
		{
			dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		for(int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				answer = max(answer, dp[i][j]);
			}
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;
		T--;
	}
}