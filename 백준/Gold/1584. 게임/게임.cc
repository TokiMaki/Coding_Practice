#include <iostream>
#include <deque>
#include <climits>

using namespace std;

int map[501][501] = {0, };
int visited[501][501];

void bfs()
{
	deque<pair<int, int>> dq;
	dq.emplace_front(0, 0);
	visited[0][0] = 0;

	int dirX[4] = {1, 0, -1, 0};
	int dirY[4] = {0, 1, 0, -1};
	while(!dq.empty())
	{
		int nowX = dq.front().first;
		int nowY = dq.front().second;
		dq.pop_front();

		for(int i = 0; i < 4; ++i)
		{
			int nextX = nowX + dirX[i];
			int nextY = nowY + dirY[i];
			if (nowX + dirX[i] >= 0 && nowX + dirX[i] <= 500 && nowY + dirY[i] >= 0 && nowY + dirY[i] <= 500)
			{
				if (map[nextY][nextX] == 0) {
					if (visited[nextY][nextX] > visited[nowY][nowX])
					{
						visited[nextY][nextX] = visited[nowY][nowX];
						dq.emplace_front(nextX, nextY);
					}
				}
				else if (map[nextY][nextX] == 1)
				{
					if (visited[nextY][nextX] > visited[nowY][nowX] + 1)
					{
						visited[nextY][nextX] = visited[nowY][nowX] + 1;
						dq.emplace_back(nextX, nextY);
					}
				}
			}
		}
	}
}

int main()
{
	int N, M;

	int x1, y1, x2, y2;

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		int maxX = max(x1, x2);
		int minX = min(x1, x2);
		int maxY = max(y1, y2);
		int minY = min(y1, y2);
		for (int j = minY; j <= maxY; ++j)
		{
			for (int k = minX; k <= maxX; ++k)
			{	
				map[j][k] = 1;
			}
		}
	}
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> x1 >> y1 >> x2 >> y2;
		int maxX = max(x1, x2);
		int minX = min(x1, x2);
		int maxY = max(y1, y2);
		int minY = min(y1, y2);
		for (int j = minY; j <= maxY; ++j)
		{
			for (int k = minX; k <= maxX; ++k)
			{
				map[j][k] = 2;
			}
		}
	}
	for (int i = 0; i < 501; ++i) 
	{
		fill_n(visited[i], 501, INT_MAX);
	}
	bfs();
	if (visited[500][500] == INT_MAX)
		cout << -1;
	else
		cout << visited[500][500];
}