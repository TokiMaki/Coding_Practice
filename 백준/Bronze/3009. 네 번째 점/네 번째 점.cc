#include <iostream>
#include <climits>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<int, int> x;
	map<int, int> y;

	for (int i = 0; i < 3; ++i) {
		int temp;
		cin >> temp;
		x[temp]++;
		cin >> temp;
		y[temp]++;
	}

	for (auto it = x.cbegin(); it != x.cend(); it++) {
		if (it->second <= 1)
			cout << it->first << " ";
	}

	for (auto it = y.cbegin(); it != y.cend(); it++) {
		if (it->second <= 1)
			cout << it->first;
	}
}