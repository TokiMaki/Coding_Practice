#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int dp[501][501] = { 0, };

int main()
{
	int N;
	cin >> N;
	vector<pair<int, int>> v(N + 1);
	for(int i = 1; i <= N; ++i)
	{
		int r, c;
		cin >> r >> c;
		v[i] = make_pair(r, c);
	}

	for(int i = 1; i <= N; ++i)
	{
		for(int j = 1; j <= N - i; ++j)
		{
			dp[j][i + j] = INT_MAX;
			for(int k = j; k < i + j; ++k)
			{
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + (v[j].first * v[k].second * v[i + j].second));
			}
		}
	}

	cout << dp[1][N];
}