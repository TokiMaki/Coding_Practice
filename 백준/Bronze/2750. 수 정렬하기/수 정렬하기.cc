#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	vector<int> v;
	int temp;

	cin >> N;

	for (int i = 0; i < N; ++i) {
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	for (int i : v) {
		cout << i << endl;
	}
}