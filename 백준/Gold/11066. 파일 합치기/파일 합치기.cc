#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int sum[501];
int dp[501][501];

int main()
{
	int T, K;
	cin >> T;
	
	while (T-- > 0)
	{
		cin >> K;
		vector<int> v(K + 1);
		fill_n(sum, 501, 0);
		for(int i = 0; i < 501; ++i)
			fill_n(dp[i], 501, 0);
		for(int i = 1; i <= K; ++i)
		{
			cin >> v[i];
			sum[i] = sum[i - 1] + v[i];
		}

		for (int i = 1; i <= K; ++i)		// 범위 크기 if i == 1 이면 한칸
		{
			for (int j = 1; j <= K - i; ++j)	// 범위 시작
			{
				dp[j][i + j] = INT_MAX;
				for(int k = j; k < i + j; ++k)	// 범위 순회
				{
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
				}
			}
		}

		cout << dp[1][K] << endl;
	}

}