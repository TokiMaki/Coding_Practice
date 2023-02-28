#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int main() {
	long long answer = 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;
	vector<pair<int, int>> info(N, make_pair(0, INT_MAX));		// first 다음까지 거리 0일경우 종착지, second 리터당 기름값;

	for (int i = 0; i < N - 1; ++i) {
		cin >> info[i].first;
	}
	for (int i = 0; i < N; ++i) {
		cin >> info[i].second;
	}

	info[N - 1].second = INT_MAX;

	auto a = min_element(info.cbegin(), info.cend(), [&](pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
		});
	
	for (int i = 0; i < N - 1; ++i) {
		if (info[i].second <= a->second) {
			for (int j = i; j < N - 1; ++j) {
				long long distance = info[j].first;
				answer += distance * info[i].second;
			}
			break;
		}
		else {
			long long distance = info[i].first;
			answer += distance * info[i].second;
		}
	}

	cout << answer;
}