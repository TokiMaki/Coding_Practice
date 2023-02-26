#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int chessboard[2001][2001] = { 0, };

int N, M, K;

int check(int x, int y) {
	int returnValue = INT_MAX;

	returnValue = chessboard[x][y] - chessboard[x - K][y] - chessboard[x][y - K] + chessboard[x - K][y - K];
	returnValue = min(returnValue, K * K - returnValue);

	return returnValue;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	int answer = INT_MAX;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			char tmp;
			cin >> tmp;
			if (((i + j) % 2 == 0 && tmp == 'B') || ((i + j) % 2 == 1 && tmp == 'W'))
				chessboard[i][j] = 1;
			chessboard[i][j] += chessboard[i - 1][j] + chessboard[i][j - 1] - chessboard[i - 1][j - 1];
		}
	}

	for (int i = N; i >= K; --i) {
		for (int j = M; j >= K; --j) {
			answer = min(answer, check(i, j));
		}
	}

	cout << answer;
}