#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void d(int N, int M, int index, int x) {
	static bool b[8] = { false, };
	static vector<int> v;
	if (x >= M) {
			for (int i : v)
				cout << i + 1 << " ";
			cout << "\n";
		return;
	}
	for (int i = index; i < N; ++i) {
		if (b[i] == false) {
			v.push_back(i);
			b[i] = true;
			d(N, M, i + 1, x + 1);
			v.pop_back();
			b[i] = false;
		}
	}
}

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	d(N, M, 0, 0);
}