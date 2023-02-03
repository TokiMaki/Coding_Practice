#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	int count = 0;

	bool A[100][100] = {false, };

	cin >> N;

	for (int i = 0; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		for (int j = x; j < x + 10; ++j) {
			for (int k = y; k < y + 10; ++k) {
				A[j][k] = true;
			}
		}
	}

	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (A[i][j] == true)
				count++;
		}
	}

	cout << count;
}