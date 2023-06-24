#include <string>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

vector<vector<pair<int, int>>> table_shapes;
vector <pair<int, int>> table_shape;
vector<vector<pair<int, int>>> board_shapes;
vector <pair<int, int>> board_shape;

void table_dfs(vector<vector<int>>& table, int tx, int ty) {
	int boardsize = table.size();

	table[ty][tx] = 0;
	table_shape.emplace_back(tx, ty);

	for (int i = 0; i < 4; ++i) {
		int next_tx = dir_x[i] + tx;
		if (next_tx < 0 || next_tx > boardsize - 1)
			continue;
		int next_ty = dir_y[i] + ty;
		if (next_ty < 0 || next_ty > boardsize - 1)
			continue;
		if (table[next_ty][next_tx] == 1) {
			table_dfs(table, next_tx, next_ty);
		}
	}
}

void board_dfs(vector<vector<int>>& game_board, int x, int y) {
	int boardsize = game_board.size();

	game_board[y][x] = 1;
	board_shape.emplace_back(x, y);
	for (int i = 0; i < 4; ++i) {
		int next_x = dir_x[i] + x;
		if (next_x < 0 || next_x > boardsize - 1)
			continue;
		int next_y = dir_y[i] + y;
		if (next_y < 0 || next_y > boardsize - 1)
			continue;
		if (game_board[next_y][next_x] == 0) {
			board_dfs(game_board, next_x, next_y);
		}
	}
}

vector<vector<int>> rotateboard(vector<vector<int>> game_board)
{
	int boardsize = game_board.size();
	vector<vector<int>> returnboard;
	returnboard = game_board;
	for(int i = 0; i < boardsize; ++i)
	{
		for(int j = 0; j < boardsize; ++j)
		{
			returnboard[i][j] = game_board[boardsize - 1 - j][i];
		}
	}
	return returnboard;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
	int answer = 0;
	int boardsize = game_board.size();

	
	for (int j = 0; j < boardsize; ++j) {
		for (int k = 0; k < boardsize; ++k) {
			if (table[j][k] == 1) {
				table_dfs(table, k, j);
				int min_x = INT_MAX;
				int min_y = INT_MAX;
				for (int l = 0; l < table_shape.size(); ++l) {
					min_x = min(min_x, table_shape[l].first);
					min_y = min(min_y, table_shape[l].second);
				}
				for (int l = 0; l < table_shape.size(); ++l) {
					table_shape[l].first -= min_x;
					table_shape[l].second -= min_y;
				}
				table_shapes.push_back(table_shape);
				table_shape.clear();
			}
		}
	}

	vector<bool> visited(table_shapes.size());

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < boardsize; ++j) {
			for (int k = 0; k < boardsize; ++k) {
				if (game_board[j][k] != 0)
					continue;
				board_dfs(game_board, k, j);
				int min_x = INT_MAX;
				int min_y = INT_MAX;
				for (int l = 0; l < board_shape.size(); ++l) {
					min_x = min(min_x, board_shape[l].first);
					min_y = min(min_y, board_shape[l].second);
				}
				vector<pair<int, int>> sort_board_shape;
				for (int l = 0; l < board_shape.size(); ++l) {
					int x = board_shape[l].first - min_x;
					int y = board_shape[l].second - min_y;
					sort_board_shape.emplace_back(x, y);
				}
				bool check = false;
				for (int l = 0; l < table_shapes.size(); ++l)
				{
					if (table_shapes[l] == sort_board_shape && visited[l] == false) {
						check = true;
						visited[l] = true;
						break;
					}
				}
				if (check == true) {
					answer += board_shape.size();
				}
				else
				{
					for(pair<int, int> p : board_shape)
					{
						game_board[p.second][p.first] = 0;
					}
				}
				board_shape.clear();
			}
		}
		game_board = rotateboard(game_board);
	}
	return answer;
}