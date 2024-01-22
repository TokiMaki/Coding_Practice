#include <iostream>

using namespace std;

int map[50][50];
int visited[50][50];
int w, h;

void Dfs(int x, int y)
{
	visited[y][x] = true;
	int dirX[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	int dirY[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

	for(int i = 0; i < 8; ++i)
	{
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX < 0 || nextX >= w)
			continue;
		if (nextY < 0 || nextY >= h)
			continue;

		if (map[nextY][nextX] == 1 && visited[nextY][nextX] == false)
		{
			Dfs(nextX, nextY);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while(true)
	{
		int answer = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; ++i) {
			fill_n(visited[i], w, false);
		}

		for(int i = 0; i < h; ++i)
		{
			for(int j = 0; j < w; ++j)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (map[i][j] == 1 && visited[i][j] == false)
				{
					Dfs(j, i);
					answer++;
				}
			}
		}
		cout << answer << endl;
	}
}