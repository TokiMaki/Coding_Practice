#include <iostream>

using namespace std;

int matrix[5][5] = { 0, };
int temp[5][5] = { 0, };
int answer[5][5] = { 0, };

void matrix_multiply(int N, int a[5][5], int b[5][5]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			temp[i][j] = 0;
			for (int k = 0; k < N; ++k) {
				temp[i][j] += a[i][k] * b[k][j];
			}
			temp[i][j] %= 1000;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = temp[i][j];
		}
	}
}

int main() {
	int N;
	long long B;
	cin >> N >> B;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> matrix[i][j];
		}
		answer[i][i] = 1;
	}

	while (B > 0) {
		if (B % 2 == 1) 
			matrix_multiply(N, answer, matrix);
		matrix_multiply(N, matrix, matrix);
		B /= 2;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}
}