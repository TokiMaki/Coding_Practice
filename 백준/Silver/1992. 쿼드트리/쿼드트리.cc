#include <iostream>

using namespace std;

int arr[64][64];

void QuadTree(int x, int y, int N) {
	bool oneColor = true;
	int startcolor = -1;
	for (int i = y; i < y + N; ++i) {
		for (int j = x; j < x + N; ++j) {
			if (startcolor == -1)
				startcolor = arr[i][j];
			else if (startcolor != arr[i][j]) {
				oneColor = false;
				break;
			}
		}
	}
	if (!oneColor) {
		if (N >= 2) {
			cout << "(";
			QuadTree(x, y, N / 2);
			QuadTree(x + (N / 2), y, N / 2);
			QuadTree(x, y + (N / 2), N / 2);
			QuadTree(x + (N / 2), y + (N / 2), N / 2);
			cout << ")";
		}
	}
	else {
		cout << startcolor;
	}
};

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < N; ++j) {
			arr[i][j] = s[j] - '0';
		}
	}
	QuadTree(0, 0, N);
}