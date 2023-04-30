#include <iostream>

using namespace std;

int field[50][50] = { 0, };
bool visited[50][50];
int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };
int M, N, K;

void bfs(int x, int y)
{
	visited[y][x] = true;
	for(int i = 0; i < 4; ++i)
	{
		int nextx = x + dir_x[i];
		int nexty = y + dir_y[i];
		if ((nextx < 0 || nextx >= M) || (nexty < 0 || nexty >= N)) 
			continue;
		if (field[nexty][nextx] == 1 && visited[nexty][nextx] == false)
		{
			bfs(nextx, nexty);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while(T-- > 0)
	{
		cin >> M >> N >> K;

		int answer = 0;

		for(int i = 0; i < N; ++i)
		{
			fill_n(field[i], M, 0);
			fill_n(visited[i], M, false);
		}

		for(int i = 0; i < K; ++i)
		{
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}

		for(int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (field[i][j] == 1 && visited[i][j] == false)
				{
					answer++;
					bfs(j, i);
				}
			}
		}

		cout << answer << "\n";
	}
}