#include <iostream>

using namespace std;

char picture[100][100];
bool visited[100][100];
bool greenVisited[100][100];

int N;

int dirX[4] = { 1, 0, -1, 0 };
int dirY[4] = { 0, 1, 0, -1 };

void Dfs(int x, int y)
{
	visited[y][x] = true;
	for(int i = 0; i < 4; ++i)
	{
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX < 0 || nextX >= N)
			continue;
		if (nextY < 0 || nextY >= N)
			continue;

		if (picture[y][x] == picture[nextY][nextX] 
			&& visited[nextY][nextX] == false)
		{
			Dfs(nextX, nextY);
		}
	}
}

void GreenDfs(int x, int y)
{
	greenVisited[y][x] = true;
	for (int i = 0; i < 4; ++i)
	{
		bool check = false;
		int nextX = x + dirX[i];
		int nextY = y + dirY[i];

		if (nextX < 0 || nextX >= N)
			continue;
		if (nextY < 0 || nextY >= N)
			continue;

		if (greenVisited[nextY][nextX] == false)
		{
			if (picture[y][x] == picture[nextY][nextX])
				check = true;
			else if ((picture[y][x] == 'R' || picture[y][x] == 'G')
				&& (picture[nextY][nextX] == 'R' || picture[nextY][nextX] == 'G'))
				check = true;
		}

		if (check)
		{
			GreenDfs(nextX, nextY);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int answer[2] = { 0, 0 };

	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> picture[i][j];
		}
	}

	for(int i = 0; i < N; ++i)
	{
		fill_n(visited[i], N, false);
		fill_n(greenVisited[i], N, false);
	}

	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j] == false) {
				Dfs(j, i);
				answer[0]++;
			}
			if (greenVisited[i][j] == false) {
				GreenDfs(j, i);
				answer[1]++;
			}
		}
	}

	cout << answer[0] << " " << answer[1];
}