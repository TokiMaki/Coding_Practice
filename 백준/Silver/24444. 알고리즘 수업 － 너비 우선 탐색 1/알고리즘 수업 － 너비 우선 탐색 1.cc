#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[100001];
int visited[100001] = { 0, };

void bfs(int start)
{
	static int cnt = 0;
	queue<int> q;
	visited[start] = ++cnt;
	q.push(start);
	while(!q.empty())
	{
		int s = q.front();
		q.pop();
		for(int i : graph[s])
		{
			if (visited[i] == 0) {
				visited[i] = ++cnt;
				q.push(i);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M, R;
	cin >> N >> M >> R;
	for(int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	for (int i = 1; i <= N; ++i)
		sort(graph[i].begin(), graph[i].end());

	bfs(R);
	for(int i = 1; i <= N; ++i)
	{
		cout << visited[i] << "\n";
	}
}