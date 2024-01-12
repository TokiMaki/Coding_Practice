#include <iostream>
#include <queue>

using namespace std;

int map[8][8];
int tempMap[8][8];
int N, M;
int answer = 0;

void copyMap()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			tempMap[i][j] = map[i][j];
		}
	}
}

void bfs()
{
	int dirX[4] = { 1, 0, -1, 0 };
	int dirY[4] = { 0, 1, 0, -1 };

	int count = 0;

	queue<pair<int, int>> q;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (tempMap[i][j] == 2)
			{
				q.emplace(j, i);
			}
		}
	}
	while(!q.empty())
	{
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int nextX = nowX + dirX[k];
			int nextY = nowY + dirY[k];
			if (nextX >= M || nextX < 0)
				continue;
			if (nextY >= N || nextY < 0)
				continue;
			if (tempMap[nextY][nextX] == 0)
			{
				tempMap[nextY][nextX] = 2;
				q.emplace(nextX, nextY);
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (tempMap[i][j] == 0)
				count++;
		}
	}

	answer = max(answer, count);
}

void wall(int current)
{
	if (current == 3)
	{
		copyMap();
		bfs();
		return;
	}

	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				wall(current + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	
	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				wall(1);
				map[i][j] = 0;
			}
		}
	}

	cout << answer;
}