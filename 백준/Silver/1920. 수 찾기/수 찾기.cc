#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> v;
	int N, M;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; ++i) {
		int tmp;
		cin >> tmp;
		if (binary_search(v.cbegin(), v.cend(), tmp))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}