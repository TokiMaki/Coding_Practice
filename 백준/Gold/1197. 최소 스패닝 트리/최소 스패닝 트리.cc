#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10001];
vector<pair<int, pair<int, int>>> graphs;

int findParent(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	parent[b] = a;
}

int main() {
	int V, E;
	int answer = 0;

	cin >> V >> E;

	for(int i = 0; i < 10001; ++i)
	{
		parent[i] = i;
	}

	for(int i = 0; i < E; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		graphs.push_back({ C, { A, B } });
	}

	sort(graphs.begin(), graphs.end());

	for(pair<int, pair<int, int>> graph : graphs)
	{
		int cost = graph.first;
		int a = graph.second.first;
		int b = graph.second.second;
		if (findParent(a) != findParent(b))
		{
			unionParent(a, b);
			answer += cost;
		}
	}

	cout << answer;
}