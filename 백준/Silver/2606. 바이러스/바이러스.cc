#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[101];
bool visited[101];

void dfs(int start)
{
	visited[start] = true;

	for(int i : graph[start])
	{
		if (visited[i] == false)
			dfs(i);
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;

	fill_n(visited, 101, false);

	for(int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	dfs(1);

	int cnt = 0;
	for (int i = 2; i <= N; ++i)
	{
		if (visited[i] == true)
			cnt++;
	}
	cout << cnt;
}