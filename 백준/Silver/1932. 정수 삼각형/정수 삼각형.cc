#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int triangle[501][501] = { 0, };

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < i; ++j) {
			int tmp;
			cin >> tmp;
			triangle[i][j] = tmp;
		}
	}
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (j == 0) {
				triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
			}
			else if (j == i - 1) {
				triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
			}
			else {
				triangle[i][j] = max(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
			}
		}
	}
	int maxcost = INT_MIN;

	for (int i = 0; i < N; ++i) {
		maxcost = max(maxcost, triangle[N][i]);
	}
	cout << maxcost;
}