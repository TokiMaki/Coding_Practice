#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool complete = false;
int board[9][9];
int completeboard[9][9];
vector<pair<int, int>> v;

bool promising(int x, int y) {
	bool check[10];
	fill_n(check, 10, false);
	int xx = (x / 3) * 3;
	int yy = (y / 3) * 3;
	for (int i = xx; i < xx + 3; ++i) {
		for (int j = yy; j < yy + 3; ++j) {
			if (board[i][j] == 0) {
				continue;
			}
			else if (check[board[i][j]] == false) {
				check[board[i][j]] = true;
			}
			else
				return false;
		}
	}
	fill_n(check, 10, false);
	for (int j = 0; j < 9; ++j) {
		if (board[x][j] == 0) {
			continue;
		}
		else if (check[board[x][j]] == false) {
			check[board[x][j]] = true;
		}
		else
			return false;
	}
	fill_n(check, 10, false);
	for (int i = 0; i < 9; ++i) {
		if (board[i][y] == 0) {
			continue;
		}
		if (check[board[i][y]] == false) {
			check[board[i][y]] = true;
		}
		else
			return false;
	}
	return true;
}

void sudoku(int x) {
	if (complete == true)
		return;
	if (x >= v.size()) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				completeboard[i][j] = board[i][j];
				complete = true;
			}
		}
		return;
	}
	for (int i = 1; i <= 9; ++i) {
		board[v[x].first][v[x].second] = i;
		if (promising(v[x].first, v[x].second))
			sudoku(x + 1);
		board[v[x].first][v[x].second] = 0;
	}
}

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> board[i][j];
			if (board[i][j] == 0)
				v.push_back(make_pair(i, j));
		}
	}
	sudoku(0);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << completeboard[i][j] << " ";
		}
		cout << "\n";
	}
}