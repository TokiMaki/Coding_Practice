#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long N, M;
vector<pair<long, long>> graph[501];
long visited[501];

bool bellmanford(long start)
{
	visited[start] = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 1; j <= N; ++j) {
			for (const auto &p : graph[j])
			{
				long to = p.first;
				long cost = p.second;
				if (visited[j] == INT_MAX)
					continue;
				if (visited[to] > visited[j] + cost)
					visited[to] = visited[j] + cost;
			}
		}
	}

	for (int j = 1; j <= N; ++j) {
		for (const auto &p : graph[j])
		{
			long to = p.first;
			long cost = p.second;
			if (visited[j] == INT_MAX)
				continue;
			if (visited[to] > visited[j] + cost)
				return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		graph[A].emplace_back(B, C);
	}

	fill_n(visited, 501, INT_MAX);

	if (bellmanford(1))
	{
		for (int i = 2; i <= N; ++i)
		{
			if (visited[i] != INT_MAX)
				cout << visited[i] << "\n";
			else
				cout << -1 << "\n";
		}
	}
	else {
		cout << -1;
	}
}