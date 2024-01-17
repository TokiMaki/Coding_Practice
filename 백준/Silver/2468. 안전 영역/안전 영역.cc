#include <iostream>

using namespace std;

int N;
int map[100][100];
int visited[100][100];
int rainHeight = 0;

int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };


void Dfs(int x, int y)
{
	visited[y][x] = true;

	for(int i = 0; i < 4; ++i)
	{
		int nextX = x + dirX[i];
		if (nextX < 0 || nextX >= N)
			continue;
		int nextY = y + dirY[i];
		if (nextY < 0 || nextY >= N)
			continue;

		if (visited[nextY][nextX] == false && map[nextY][nextX] > rainHeight)
		{
			Dfs(nextX, nextY);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer = 0;
	cin >> N;

	int maxHeight = 0;


	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> map[i][j];
			maxHeight = max(maxHeight, map[i][j]);
		}
	}

	while(rainHeight <= maxHeight)
	{
		int safeZone = 0;
		for (int i = 0; i < N; ++i)
			fill_n(visited[i], N, false);
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (visited[i][j] == false && map[i][j] > rainHeight)
				{
					Dfs(j, i);
					safeZone++;
				}
			}
		}
		answer = max(answer, safeZone);
		rainHeight++;
	}

	cout << answer;
}