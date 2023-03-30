#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

int N, M, V;
vector<set<int>> Graph;
vector<bool> Visit;

void Dfs(int V) {
	Visit[V] = true;
	cout << V << " ";
	for (auto a : Graph[V])
	{
		int nextV = a;
		if (!Visit[nextV])
			Dfs(nextV);
	}
}

void Bfs(int V) {
	queue<int> q;
	Visit[V] = true;
	q.push(V);
	while (!q.empty()) {
		int start = q.front();
		cout << start << " ";
		q.pop();
		for (auto a : Graph[start])
		{
			int nextV = a;
			if (!Visit[nextV]) {
				Visit[nextV] = true;
				q.push(nextV);
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;
	Graph.reserve(N + 1);
	for (int i = 0; i <= N; ++i) 
	{
		Graph.emplace_back();
	}

	Visit.reserve(N + 1);
	for (int i = 0; i <= N; ++i) 
	{
		Visit.push_back(false);
	}

	for (int i = 0; i < M; ++i) 
	{
		int a, b;
		cin >> a >> b;
		auto p = make_pair(a, b);
		Graph[a].insert(b);
		Graph[b].insert(a);
	}

	fill(Visit.begin(), Visit.end(), false);
	Dfs(V);
	cout << endl;
	fill(Visit.begin(), Visit.end(), false);
	Bfs(V);
}