#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A[9][9];
	int x = 0;
	int y = 0;
	int max = 0;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> A[i][j];
			if (max < A[i][j]) {
				max = A[i][j];
				x = i;
				y = j;
			}
		}
	}

	cout << max << "\n" << x + 1 << " " << y + 1;
}