#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
set<vector<int>> withoutv;

void d(int N, int M, int x) {
	static bool b[8] = { false, };
	static vector<int> v;
	if (x >= M) {
		vector<int> tmp;
		for (int i : v)
			tmp.push_back(i);
		sort(tmp.begin(), tmp.end());
		if (withoutv.end() == withoutv.find(tmp)) {
			withoutv.insert(tmp);
			for (int i : v)
				cout << i + 1 << " ";
			cout << "\n";
		}
		return;
	}
	for (int i = 0; i < N; ++i) {
		if (b[i] == false) {
			v.push_back(i);
			b[i] = true;
			d(N, M, x + 1);
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
	d(N, M, 0);
}