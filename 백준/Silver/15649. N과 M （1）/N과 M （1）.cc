#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool isduplication(int* num, int x) {
	set<int> s;
	for (int i = 0; i < x + 1; ++i) {
		s.insert(num[i]);
	}
	return (s.size() == x + 1);
}

void dfs(int N, int M, int x) {
	static int num[8];
	if (x == M) {
		for (int i = 0; i < M; ++i) {
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 1; i <= N; ++i) {
			num[x] = i;
			if (isduplication(num, x)) {
				dfs(N, M, x + 1);
			}
		}
	}
}

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	dfs(N, M, 0);
}