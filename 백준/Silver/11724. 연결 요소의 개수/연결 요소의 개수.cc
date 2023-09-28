#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool visited[1001];
int N, M;
vector<vector<int>> v(1001);

void dfs(int n)
{
	visited[n] = true;

	for(int i : v[n])
	{
		if (visited[i] == false)
		{
			dfs(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int answer = 0;

	fill_n(visited, 1001, false);
	for(int i = 0; i < M; ++i)
	{
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
		v[e].push_back(s);
	}

	for(int i = 1; i <= N; ++i)
	{
		if (visited[i] == false) {
			dfs(i);
			answer++;
		}
	}

	cout << answer;
}