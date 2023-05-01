#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int l;
int end_x, end_y;
int answer = INT_MAX;
int visited[300][300];

void bfs(int sx, int sy, int cnt)
{
	queue<pair<pair<int,int>, int>> q;
	q.push({{ sx, sy }, cnt});

	int dir_x[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int dir_y[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

	while(!q.empty())
	{
		int front_x = q.front().first.first;
		int front_y = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (front_x == end_x && front_y == end_y)
		{
			answer = min(answer, c);
			continue;
		}

		for (int i = 0; i < 8; ++i)
		{
			int next_x = front_x + dir_x[i];
			int next_y = front_y + dir_y[i];
			if ((next_x >= l || next_x < 0)
				|| (next_y >= l || next_y < 0))
				continue;
			if (visited[next_y][next_x] > c + 1) {
				visited[next_y][next_x] = c + 1;
				q.push({ { next_x, next_y }, c + 1 });
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, start_x, start_y;

	cin >> T;

	while(T-- > 0)
	{
		answer = INT_MAX;
		cin >> l >> start_x >> start_y;
		cin >> end_x >> end_y;

		for (int i = 0; i < 300; ++i) {
			fill_n(visited[i], 300, INT_MAX);
		}
		bfs(start_x, start_y, 0);

		cout << answer << "\n";
	}
}