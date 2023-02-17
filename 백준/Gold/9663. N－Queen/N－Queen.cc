#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int chess[15];

bool promising(int x, int* chessborad) {
	for (int i = 0; i < x; ++i) {
		if (chessborad[x] == chessborad[i] || (x - i) == abs(chessborad[x] - chessborad[i]))
			return false;
	}
	return true;
}

void nQueen(int* count, int n, int x) {
	if (x >= n) {
		*count += 1;
		return;
	}
	for (int i = 0; i < n; ++i) {
		chess[x] = i;
		if (true == promising(x, chess)) {
			nQueen(count, n, x + 1);
		}
	}
}

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int count = 0;
	cin >> N;
	nQueen(&count, N, 0);
	cout << count;
}