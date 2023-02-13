#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> v;
	int direction[4] = {0, };

	int result = 0;

	int K;
	cin >> K;

	int big = 1;
	int small = 1;

	for (int i = 0; i < 6; ++i) {
		pair<int, int> tmp;
		cin >> tmp.first >> tmp.second;
		v.push_back(tmp);
		direction[tmp.first - 1]++;
	}

	int start = -1;
	int i = 0;
	int continuous = 0;
	while (true) {
		if (direction[v[i].first - 1] <= 1) {
			big *= v[i].second;
			continuous++;
		}
		else {
			big = 1;
			continuous = 0;
		}
		if (continuous >= 2) {
			start = i;
			break;
		}
		i = (i + 1) % 6;
	}

	small = v[(start + 2) % 6].second * v[(start + 3) % 6].second;

	result = K * (big - small);

	cout << result;
}