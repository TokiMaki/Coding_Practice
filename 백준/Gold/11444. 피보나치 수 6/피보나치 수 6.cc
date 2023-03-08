#include <iostream>

using namespace std;

long long matrix[2][2] = { 1, 1, 1, 0 };
long long temp[2][2] = { 0, };
long long answer[2][2] = { 0, };

void matrix_multiply(long long N, long long a[2][2], long long b[2][2]) {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			temp[i][j] = 0;
			for (int k = 0; k < N; ++k) {
				temp[i][j] += a[i][k] * b[k][j];
			}
			temp[i][j] %= 1000000007;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = temp[i][j];
		}
	}
}

int main() {
	long long N;
	cin >> N;

	for (int i = 0; i < 2; ++i)
		answer[i][i] = 1;

	while (N > 0) {
		if (N % 2 == 1) 
			matrix_multiply(2, answer, matrix);
		matrix_multiply(2, matrix, matrix);
		N /= 2;
	}

	cout << answer[0][1];
}