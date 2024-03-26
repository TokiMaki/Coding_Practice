#include <iostream>

using namespace std;

int room[51][51];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;
	int N, M;
	int r, c, d;
	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> room[i][j];
		}
	}

	int dirX[4] = { 0, 1, 0, -1 };
	int dirY[4] = { -1, 0, 1, 0 };

	while (true) {
		if (room[r][c] == 0) {
			room[r][c] = 2;
			answer++;
		}
		bool clear = true;
		for (int i = 0; i < 4; ++i) {
			d = (d + 3) % 4;
			int nextR = r + dirY[d];
			if (nextR < 0 || nextR > N) continue;
			int nextC = c + dirX[d];
			if (nextC < 0 || nextC > M) continue;
			if (room[nextR][nextC] == 0) {
				r = nextR;
				c = nextC;
				clear = false;
				break;
			}
		}
		if (clear == true) {
			int backD = (d + 2) % 4;
			int nextR = r + dirY[backD];
			int nextC = c + dirX[backD];
			if (room[nextR][nextC] != 1) {
				r = nextR;
				c = nextC;
			}
			else
				break;
		}
	}

	cout << answer;
}