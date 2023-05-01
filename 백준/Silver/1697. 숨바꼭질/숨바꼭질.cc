#include <iostream>
#include <climits>
#include <queue>

using namespace std;

int N, K;
int answer = INT_MAX;
int visited[100001];

void bfs(int start, int dis, int cnt)
{
	queue<pair<int,int>> q;
	q.push({ start, cnt } );
	while(!q.empty())
	{
		int s = q.front().first;
		int c = q.front().second;
		q.pop();
		if (s == K) {
			answer = min(answer, c);
			continue;
		}
		if (s * 2 <= 100000 && (visited[s * 2] > c))
		{
			visited[s * 2] = c;
			q.push({ s * 2, c + 1} );
		}
		if (s + 1 <= 100000 && (visited[s + 1] > c))
		{
			visited[s + 1] = c;
			q.push({ s + 1, c + 1} );
		}
		if (s - 1 >= 0 && (visited[s - 1] > c))
		{
			visited[s - 1] = c;
			q.push({ s - 1, c + 1} );
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	fill_n(visited, 100001, INT_MAX);

	bfs(N, abs(K - N), 0);
	cout << answer;
}