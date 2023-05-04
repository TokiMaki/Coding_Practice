#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[1001][1001];
bool visited[2][1001][1001];

int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };

int bfs()
{
	queue<pair<pair<int, int>, pair<int, int>>> q;

	q.push({ { 1, 0 }, { 1, 1 }});
	visited[0][1][1] = 1;

	while(!q.empty())
	{
		int depth = q.front().first.first;
		int crash = q.front().first.second;
		int current_x = q.front().second.first;
		int current_y = q.front().second.second;
		q.pop();

		if (current_x == M && current_y == N)
			return depth;

		for(int i = 0; i < 4; ++i)
		{
			int next_x = current_x + dir_x[i];
			int next_y = current_y + dir_y[i];
			if (next_x < 1 || next_x > M 
				|| next_y < 1 || next_y > N)
				continue;
			if (map[next_y][next_x] == 0 && visited[crash][next_y][next_x] == 0) {
				visited[crash][next_y][next_x] = true;
				q.push({ {depth + 1, crash}, {next_x, next_y} });
			}
			else if (map[next_y][next_x] == 1 
				&& visited[1][next_y][next_x] == 0 && crash == 0) {
				visited[1][next_y][next_x] = true;
				q.push({ {depth + 1, true}, {next_x, next_y} });
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for(int i = 1; i <= N; ++i)
	{
		string s;
		cin >> s;
		for(int j = 1; j <= M; ++j)
		{
			map[i][j] = s[j - 1] - '0';
		}
	}

	cout << bfs();
}