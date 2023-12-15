#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> dp(1500002);

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> counsels;

	for (int i = 0; i < N; ++i)
	{
		pair<int, int> temp;
		cin >> temp.first >> temp.second;
		counsels.emplace_back(temp.first, temp.second);
	}

	for (int i = 1; i <= N; ++i)
	{
		int T = counsels[i - 1].first;
		int P = counsels[i - 1].second;
		dp[i] = max(dp[i], dp[i - 1]);
		if (i + T <= N + 1) {
			dp[i + T] = max(dp[i + T], dp[i] + P);
		}
	}

	cout << *max_element(dp.begin(), dp.end());
}