#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int M, N, H;
int box[100][100][100] = {0,};
int answer = -1;
queue<pair<int, pair<int, int>>> q;		// H, M, N
int dir_h[6] = { 0, 0, 0, 0, 1, -1 };
int dir_x[6] = { 1, 0, -1, 0 };
int dir_y[6] = { 0, 1, 0, -1 };

void bfs()
{
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (box[i][j][k] == 1)
					q.push({ i, {k, j} });
			}
		}
	}
	while(!q.empty())
	{
		int curr_h = q.front().first;
		int curr_x = q.front().second.first;
		int curr_y = q.front().second.second;
		q.pop();
		for(int i = 0; i < 6; ++i)
		{
			int next_h = curr_h + dir_h[i];
			int next_x = curr_x + dir_x[i];
			int next_y = curr_y + dir_y[i];
			if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N
				|| next_h < 0 || next_h >= H)
				continue;
			if (box[next_h][next_y][next_x] == 0)
			{
				box[next_h][next_y][next_x] = box[curr_h][curr_y][curr_x] + 1;
				q.push({ next_h, {next_x, next_y} });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N >> H;
	for(int i = 0; i < H; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			for(int k = 0; k < M; ++k)
			cin >> box[i][j][k];
		}
	}

	bfs();

	int trigger = false;
	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (int k = 0; k < M; ++k)
			{
				if (box[i][j][k] == 0) {
					answer = -1;
					cout << answer << endl;
					return 0;
				}
				else
					answer = max(answer, box[i][j][k] - 1);
			}
		}
		if (trigger == true)
			break;
	}
	cout << answer << endl;
}