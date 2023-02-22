#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int floornum[101][10];			// 앞의 배열은 길이, 뒷배열은 맨 마지막 숫자
	int N;
	cin >> N;

	floornum[1][0] = 0;
	for (int i = 1; i <= 9; ++i) {
		floornum[1][i] = 1;
	}

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j == 0)
				floornum[i][j] = floornum[i - 1][j + 1];
			else if (j == 9)
				floornum[i][j] = floornum[i - 1][j - 1];
			else
				floornum[i][j] = floornum[i - 1][j + 1] + floornum[i - 1][j - 1];
			floornum[i][j] %= 1000000000;
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; ++i) {
		sum += floornum[N][i];
		sum %= 1000000000;
	}
	cout << sum;
}