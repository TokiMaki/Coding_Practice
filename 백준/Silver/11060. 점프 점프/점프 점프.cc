#include <iostream>
#include <vector>

using namespace std;

vector<int> dp(1001);

int main() {
	int N;
	cin >> N;

	vector<int> v(N);

	fill_n(dp.begin(), 1001, -1);
	dp[0] = 0;

	for(int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	for(int i = 0; i < N; ++i)
	{
		if (dp[i] == -1)
			continue;
		for(int j = 1; j <= v[i]; ++j)
		{
			int next = i + j;
			if (next < N) {
				if (dp[next] == -1)
					dp[next] = dp[i] + 1;
				else
					dp[next] = min(dp[next], dp[i] + 1);
			}
		}
	}

	cout << dp[N - 1];
}