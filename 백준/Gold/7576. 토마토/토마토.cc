#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int M, N;
int box[1000][1000] = {0, };
int answer = -1;
queue<pair<int, int>> q;
int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

void bfs()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (box[i][j] == 1)
				q.push({ j, i });
		}
	}
	while(!q.empty())
	{
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();
		for(int i = 0; i < 4; ++i)
		{
			int next_x = curr_x + dir_x[i];
			int next_y = curr_y + dir_y[i];
			if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N)
				continue;
			if (box[next_y][next_x] == 0)
			{
				box[next_y][next_x] = box[curr_y][curr_x] + 1;
				q.push({next_x, next_y});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N;
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < M; ++j)
		{
			cin >> box[i][j];
		}
	}

	bfs();

	int trigger = false;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (box[i][j] == 0) {
				answer = -1;
				trigger = true;
				break;
			}
			else
				answer = max(answer, box[i][j] - 1);
		}
		if (trigger == true)
			break;
	}
	cout << answer << endl;
}