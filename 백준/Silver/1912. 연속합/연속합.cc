#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int N;
	vector<int> v;
	cin >> N;

	int dp[100001] = {0, };
	int Max = INT_MIN;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 1; i <= N; ++i) {
		if (dp[i - 1] + v[i - 1] < v[i - 1])
			dp[i] = v[i - 1];
		else
			dp[i] = (dp[i - 1] + v[i - 1]);
		Max = max(Max, dp[i]);
	}
	cout << Max;
}