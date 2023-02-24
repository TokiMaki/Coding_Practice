#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int answer = 0;
	cin >> N;
	vector<pair<int, int>> v;
	vector<int> dp;
	
	for (int i = 0; i < N; ++i) {
		int A, B;
		cin >> A >> B;
		v.push_back(make_pair(A, B));
	}

	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
		return a.first <= b.first;
		});

	for (int i = 0; i < N; ++i) {
		dp.push_back(1);
		for (int j = 0; j < i; ++j) {
			if (v[i].second > v[j].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		answer = max(answer, dp[i]);
	}

	cout << N - answer;
}