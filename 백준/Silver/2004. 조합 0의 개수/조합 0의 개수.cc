#include <iostream>
#include <algorithm>

using namespace std;

int d(int n, int r) {
	int result = 0;
	for (long long i = r; i <= n; i *= r) {
		result += n / i;
	}
	return result;
}

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	int result = 0;
	result = min((d(N, 5) - d(N - M, 5) - d(M, 5)), (d(N, 2) - d(N - M, 2) - d(M, 2)));
	cout << result;
}