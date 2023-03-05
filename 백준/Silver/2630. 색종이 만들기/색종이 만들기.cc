#include <iostream>
#include <array>

using namespace std;

int answer[2] = {0, 0};		// 0 흰색, 1 파란색
int paper[129][129];

void DividePaper(int x, int y, int N) {
	bool oneColor = true;
	int startcolor = -1;
	for (int i = x; i < x + N; ++i) {
		for (int j = y; j < y + N; ++j) {
			if (startcolor == -1)
				startcolor = paper[i][j];
			else if (startcolor != paper[i][j]) {
				oneColor = false;
				break;
			}
		}
	}
	if (!oneColor) {
		if (N >= 2) {
			DividePaper(x, y, N / 2);
			DividePaper(x + (N / 2), y, N / 2);
			DividePaper(x, y + (N / 2), N / 2);
			DividePaper(x + (N / 2), y + (N / 2), N / 2);
		}
	}
	else
		answer[startcolor]++;
};

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> paper[i][j];
		}
	}
	DividePaper(1, 1, N);
	cout << answer[0] << '\n' << answer[1];
}