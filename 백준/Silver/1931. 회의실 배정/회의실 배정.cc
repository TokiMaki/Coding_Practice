#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> v(N);		// first = start, second = end
	for (int i = 0; i < N; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
		if (a.second != b.second)
			return a.second < b.second;
		return a.first < b.first;
		});

	int starttime = 0;
	int answer = 0;

	for (int i = 0; i < N; ++i) {
		if (v[i].first >= starttime) {
			starttime = v[i].second;
			answer++;
		}
	}

	cout << answer;
}