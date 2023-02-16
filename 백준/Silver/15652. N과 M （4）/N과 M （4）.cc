#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void d(int N, int M, int index, int x) {
	static vector<int> v;
	if (x >= M) {
		for (int i : v) {
			cout << i << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = index; i <= N; ++i) {
		v.push_back(i);
		d(N, M, i, x + 1);
		v.pop_back();
	}
}

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	d(N, M, 1, 0);
}