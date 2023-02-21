#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int triangle[501][501] = { 0, };
int maxtriangle[501][501] = { 0, };

int main() {
	int N;
	cin >> N;
	vector<int> trianglev;
	vector<int> maxtrianglev;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < i; ++j) {
			int tmp;
			cin >> tmp;
			triangle[i][j] = tmp;
			trianglev.push_back(tmp);
		}
	}
	maxtriangle[1][0] = triangle[1][0];
	maxtrianglev.push_back(trianglev[0]);
	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (j == 0) {
				maxtriangle[i][j] = maxtriangle[i - 1][j] + triangle[i][j];
			}
			else if (j == i - 1) {
				maxtriangle[i][j] = maxtriangle[i - 1][j - 1] + triangle[i][j];
			}
			else {
				maxtriangle[i][j] = max(maxtriangle[i - 1][j - 1], maxtriangle[i - 1][j]) + triangle[i][j];
			}
		}
	}
	int maxcost = INT_MIN;

	for (int i = 0; i < N; ++i) {
		maxcost = max(maxcost, maxtriangle[N][i]);
	}
	cout << maxcost;
}