#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[20001];
int visited[20001];
int K, V, E;
bool answer;

void dfs(int color, int idx)
{
	if (visited[idx] == 0)
		visited[idx] = color;
	int nextcolor = NULL;
	if (color == 1)
		nextcolor = 2;
	else if(color == 2)
		nextcolor = 1;
	for(int i : graph[idx])
	{
		if (visited[i] == 0)
		{
			visited[i] = nextcolor;
			dfs(nextcolor, i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K;

	while (K-- > 0) {
		cin >> V >> E;

		for (int i = 1; i <= V; ++i) {
			graph[i].clear();
		}

		fill_n(visited, V + 1, 0);

		for(int i = 0; i < E; ++i)
		{
			int s, e;
			cin >> s >> e;
			graph[s].push_back(e);
			graph[e].push_back(s);
		}

		for (int i = 1; i <= V; ++i) {
			if (visited[i] == 0)
				dfs(1, i);
		}

		answer = true;

		for(int i = 1; i <= V; ++i)
		{
			for(int j : graph[i])
			{
				if (visited[i] == visited[j])
				{
					answer = false;
				}
			}
		}

		if (answer == true)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}