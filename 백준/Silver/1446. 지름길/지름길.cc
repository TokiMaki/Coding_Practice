#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, D;
vector<vector<pair<int, int>>> shortCut(10001);
int cost[10001];

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	
	pq.emplace(0, 0);
	cost[0] = 0;
	while(!pq.empty())
	{
		int dist = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (cost[now] < dist) continue;
		for(pair<int, int> p : shortCut[now])
		{
			int nextEnd = p.first;
			int nextCost = dist + p.second;
			if(nextCost < cost[nextEnd])
			{
				cost[nextEnd] = nextCost;
				pq.emplace(nextCost, nextEnd);
			}
		}
	}
}

int main()
{
	int answer = 0;

	cin >> N >> D;

	for(int i = 0; i <= D; ++i)
	{
		cost[i] = INT_MAX;
		shortCut[i].emplace_back(i + 1, 1);
	}

	for(int i = 0; i < N; ++i)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		shortCut[start].emplace_back(end, cost);
	}
	dijkstra();
	cout << cost[D];
}