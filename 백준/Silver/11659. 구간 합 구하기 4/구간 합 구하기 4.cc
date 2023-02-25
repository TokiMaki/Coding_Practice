#include <iostream>

using namespace std;

int num[100001] = {0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i) {
		int tmp;
		cin >> tmp;
		num[i] = tmp + num[i - 1];
	}

	for (int i = 0; i < M; ++i) {
		int sum = 0;
		int j, k;
		cin >> j >> k;
		sum = num[k] - num[j - 1];
		cout << sum << "\n";
	}
}