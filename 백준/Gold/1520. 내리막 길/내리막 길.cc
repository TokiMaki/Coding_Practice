#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

int M, N;
int dp[501][501] = { 0, };
int map[501][501] = { 0, };
bool visited[501][501];
int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

int dfs(int x, int y)
{
	if (y == M - 1 && x == N - 1)
	{
		return 1;
	}
	if (visited[y][x])
		return dp[y][x];
	visited[y][x] = true;
	for(int i = 0; i < 4; ++i)
	{
		int compx = x + dir_x[i];
		int compy = y + dir_y[i];
		if ((compy >= 0 && compy < M)
			&& (compx >= 0 && compx < N))
		{
			if (map[compy][compx] < map[y][x])
			{
				dp[y][x] += dfs(compx, compy);
			}
		}
	}

	return dp[y][x];
}

int main()
{

	cin >> M >> N;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 501; ++i) {
		fill_n(visited[i], 501, false);
	}

	cout << dfs(0, 0);
}