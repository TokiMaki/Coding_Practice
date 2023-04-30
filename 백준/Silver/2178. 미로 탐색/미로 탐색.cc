#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int map[101][101] = { 0, };
bool visited[101][101];
int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };
int N, M;
int answer = INT_MAX;

void bfs(int x, int y)
{
	visited[y][x] = true;
	queue<pair<int, pair<int, int>>> q;
	q.push(make_pair(1, make_pair(x, y)));
	visited[0][0] = true;
	while (!q.empty()) {
		int cnt = q.front().first;
		int front_x = q.front().second.first;
		int front_y = q.front().second.second;
		q.pop();
		if (front_x == M - 1 && front_y == N - 1) {
			answer = min(answer, cnt);
			continue;
		}
		for (int i = 0; i < 4; ++i)
		{
			int nextx = front_x + dir_x[i];
			int nexty = front_y + dir_y[i];
			if ((nextx < 0 || nextx >= M) || (nexty < 0 || nexty >= N))
				continue;
			if (map[nexty][nextx] == 1 && visited[nexty][nextx] == false)
			{
				visited[nexty][nextx] = true;
				q.push({ cnt + 1, {nextx, nexty} });
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j)
		{
			map[i][j] = s[j] - '0';
		}
	}
	
	bfs(0, 0);

	cout << answer << "\n";
}