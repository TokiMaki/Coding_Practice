#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	//백준 입출력 속도 개선
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> v, ori;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		ori.push_back(temp);
	}

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i : ori) {
		int temp = lower_bound(v.begin(), v.end(), i) - v.begin();
		cout << temp << " ";
	}
}