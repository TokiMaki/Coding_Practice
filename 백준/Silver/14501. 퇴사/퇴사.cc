#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;

	cin >> N;
	vector<int> dp_v(N + 2);
	vector<int> T(N + 1);
	vector<int> P(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> T[i] >> P[i];
	}
	for (int i = 1; i <= N; ++i) {
		dp_v[i] = max(dp_v[i], dp_v[i - 1]);
		if (i + T[i] <= N + 1)
			dp_v[i + T[i]] = max(dp_v[i] + P[i], dp_v[i + T[i]]);
	}
	cout << *max_element(dp_v.begin(), dp_v.end()) << endl;
}