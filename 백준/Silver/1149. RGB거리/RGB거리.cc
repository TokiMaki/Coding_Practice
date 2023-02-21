#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
	int RGB[3];
	int cost[1001][3] = { 0, };
	int N;
	int mincost = INT_MAX;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> RGB[0] >> RGB[1] >> RGB[2];
		cost[i][0] += min(cost[i - 1][1], cost[i - 1][2]) + RGB[0];
		cost[i][1] += min(cost[i - 1][0], cost[i - 1][2]) + RGB[1];
		cost[i][2] += min(cost[i - 1][0], cost[i - 1][1]) + RGB[2];
	}
	for (int i = 0; i < 3; ++i)
		mincost = min(mincost, cost[N][i]);
	
	cout << mincost;
}