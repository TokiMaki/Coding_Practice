#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	int sum = 0;
	vector<int> v;
	vector<int> dp;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	dp.push_back(v[0]);
	dp.push_back(v[0] + v[1]);
	dp.push_back(max(v[0] + v[2], v[1] + v[2]));

	for (int i = 3; i < N; ++i) {
		dp.push_back(max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]));
	}

	cout << dp[N - 1];
}