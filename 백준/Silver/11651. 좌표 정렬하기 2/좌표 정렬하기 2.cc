#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	//백준 입출력 속도 개선
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> v;

	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first < b.first;
		else
			return a.second < b.second;
		});

	for (auto a : v) {
		cout << a.first << " " << a.second << "\n";
	}
}