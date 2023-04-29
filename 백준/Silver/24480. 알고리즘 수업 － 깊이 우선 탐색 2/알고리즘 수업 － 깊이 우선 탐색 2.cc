#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001] = { 0, };

void dfs(int start)
{
	static int cnt = 0;
	visited[start] = ++cnt;
	for(int i : graph[start])
	{
		if (visited[i] == 0)
			dfs(i);
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
		sort(graph[i].begin(), graph[i].end(), greater<int>());

	dfs(R);
	for(int i = 1; i <= N; ++i)
	{
		cout << visited[i] << "\n";
	}
}