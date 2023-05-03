#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int N, M;
int board[101];
int visited[101];
int answer;
queue<int> q;

void bfs()
{
	visited[1] = 0;
	for (int i = 1; i <= 6; ++i) {
		q.push(i + 1);
		visited[i + 1] = 1;
	}
	while(!q.empty())
	{
		int current = q.front();
		int next = board[current];
		q.pop();
		if (visited[next] == -1 
			|| (visited[next] != -1 && (visited[next] >= visited[current])))
			visited[next] = visited[current];
		else
			continue;
		if (next == 100) {
			answer = min(answer, visited[next]);
			continue;
		}

		for (int i = 1; i <= 6; ++i)
		{
			if (next + i <= 100 && 
				(visited[next + i] == -1 
					|| (visited[next] != -1 && visited[next] + 1 < visited[next + i]))) {
				visited[next + i] = visited[next] + 1;
				q.push(next + i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 1; i <= 100; ++i)
	{
		board[i] = i;
		visited[i] = -1;
	}

	answer = INT_MAX;

	cin >> N >> M;

	for(int i = 0; i < N; ++i)
	{
		int s, e;
		cin >> s >> e;
		board[s] = e;
	}

	for (int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		board[s] = e;
	}
	bfs();

	cout << answer;
}