#include <iostream>

using namespace std;

int matrix[3][101][101] = { 0, };

int main() {
	int N, M, K;
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> matrix[0][i][j];
		}
	}

	cin >> M >> K;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < K; ++j) {
			cin >> matrix[1][i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < K; ++j) {
			for (int k = 0; k < M; ++k) {
				matrix[2][i][j] += matrix[0][i][k] * matrix[1][k][j];
			}
			cout << matrix[2][i][j] << " ";
		}
		cout << '\n';
	}
}