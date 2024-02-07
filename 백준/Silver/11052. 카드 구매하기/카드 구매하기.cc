#include <iostream>
#include <vector>

using namespace std;

int dp[1001] = {0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;
	vector<int> p(N + 1);

	for(int i = 1; i <= N; ++i)
	{
		cin >> p[i];
	}

	dp[1] = p[1];

	for(int i = 2; i <= N; ++i)
	{
		dp[i] = p[i];
		for(int j = i; j > 0; --j)
		{
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}

	cout << dp[N];
}