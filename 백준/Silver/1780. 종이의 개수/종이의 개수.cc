#include <iostream>

#define MAX 3 * 3 * 3 * 3 * 3 * 3 * 3
using namespace std;


int arr[MAX][MAX];
int answer[3] = {0, };

void QuadTree(int x, int y, int N) {
	bool oneColor = true;
	int startcolor = -2;
	for (int i = y; i < y + N; ++i) {
		for (int j = x; j < x + N; ++j) {
			if (startcolor == -2)
				startcolor = arr[i][j];
			else if (startcolor != arr[i][j]) {
				oneColor = false;
				break;
			}
		}
	}
	if (!oneColor) {
		if (N >= 3) {
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					QuadTree(x + (N / 3) * i, y + (N / 3) * j, N / 3);
				}
			}
		}
	}
	else {
		if (startcolor == -1)
			answer[0]++;
		if (startcolor == 0)
			answer[1]++;
		if (startcolor == 1)
			answer[2]++;
	}
};

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}
	QuadTree(0, 0, N);
	for (int i = 0; i < 3; ++i) {
		cout << answer[i] << '\n';
	}
}