#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1001];
vector<pair<int, pair<int, int>>> graphs;

int findParent(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	int N, M;
	int answer = 0;

	cin >> N >> M;

	for(int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		graphs.push_back({ c, { a, b } });
	}

	for (int i = 0; i < 1001; ++i)
		parent[i] = i;

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