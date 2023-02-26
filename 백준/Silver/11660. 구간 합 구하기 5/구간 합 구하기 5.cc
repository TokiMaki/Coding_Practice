#include <iostream>
#include <algorithm>

using namespace std;

int table[1025][1025] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;


	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int tmp;
			cin >> tmp;
			table[i][j] += tmp;
			if (j + 1 <= N)
				table[i][j + 1] += table[i][j];
		}
	}

	int x1, x2;
	int y1, y2;
	for (int i = 0; i < M; ++i) {
		cin >> x1 >> x2 >> y1 >> y2;
		pair<int, int> xminmax = minmax(x1, y1);
		pair<int, int> yminmax = minmax(x2, y2);
		int result = 0;
		for (int j = xminmax.first; j <= xminmax.second; ++j) {
				result += (table[j][yminmax.second] - table[j][yminmax.first - 1]);
		}
		cout << result << "\n";
	}
}