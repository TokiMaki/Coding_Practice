#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <climits>

using namespace std;

int T, n, m, t, s, g, h;
vector<pair<int, int>> graph[2001];
int visited[2001];

void dijkstra(int start)
{
	fill_n(visited, n + 1, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	visited[start] = 0;
	pq.push({ 0, start });

	while(!pq.empty())
	{
		int curr_dis = pq.top().first;
		int curr_start = pq.top().second;
		pq.pop();
		for(auto p : graph[curr_start])
		{
			int next_start = p.first;
			int next_dis = p.second;
			if (visited[next_start] > curr_dis + next_dis)
			{
				visited[next_start] = curr_dis + next_dis;
				pq.push({ visited[next_start], next_start });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while(T-- > 0)
	{
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		for (int i = 0; i <= n; ++i)
			graph[i].clear();
		for(int i = 0; i < m; ++i)
		{
			int v1, v2;
			int dis;
			cin >> v1 >> v2 >> dis;
			graph[v1].emplace_back(v2, dis);
			graph[v2].emplace_back(v1, dis);
		}

		set<int> disv;

		for(int i = 0; i < t; ++i)
		{
			int d;
			cin >> d;

			int sTod, sTog, sToh, gToh, hTod, gTod;
			dijkstra(s);
			sTod = visited[d];
			sTog = visited[g];
			sToh = visited[h];

			dijkstra(g);
			gToh = visited[h];
			gTod = visited[d];

			dijkstra(h);
			hTod = visited[d];

			if (gToh == INT_MAX)
				continue;
			if (sTog != INT_MAX && hTod != INT_MAX)
			{
				if (sTod == (sTog + gToh + hTod))
					disv.insert(d);
			}
			if (sToh != INT_MAX && gTod != INT_MAX)
			{
				if (sTod == (sToh + gToh + gTod))
					disv.insert(d);
			}
		}
		
		for (int i : disv)
			cout << i << " ";
		cout << "\n";
	}
}