#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<pair<int, int>> graph[20001];
int dis[20001];
int V, E, K;


void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dis[start] = 0;

	while(!pq.empty())
	{
		int curr_distance = pq.top().first;
		int curr_start = pq.top().second;
		pq.pop();

		for(auto p : graph[curr_start])
		{
			int next_start = p.first;
			int next_distance = p.second;
			if (dis[next_start] > curr_distance + next_distance) {
				dis[next_start] = curr_distance + next_distance;
				pq.push({ curr_distance + next_distance, next_start });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int inf = INT_MAX;


	cin >> V >> E;
	cin >> K;


	fill_n(dis, V + 1, inf);

	for(int i = 0; i < E; ++i)
	{
		int s, e, dis;
		cin >> s >> e >> dis;
		graph[s].emplace_back( e, dis );
	}

	dijkstra(K);

	for(int i = 1; i <= V; ++i)
	{
		if (dis[i] != inf)
			cout << dis[i] << "\n";
		else
			cout << "INF" << "\n";
	}
}