#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		v.emplace_back(tmp);
	}
	sort(v.begin(), v.end());
	cout << *v.cbegin() * *v.crbegin();
}