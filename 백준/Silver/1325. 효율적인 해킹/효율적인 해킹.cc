#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[10001];
vector<int> hackNum(10001);
int answer = 0;
vector<int> route;
vector<int> graph[10001];

void BFS(int v) {
	visited[v] = true;
	queue<int> q;
	q.push(v);

	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (int i : graph[front]) {
			if (visited[i] == false) {
				visited[i] = true;
				q.push(i);
				hackNum[v]++;
			}
		}
	}
}

int main() {
	vector<int> answer;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int start, end;
		cin >> end >> start;
		graph[start].push_back(end);
	}
	
	for (int i = 1; i <= N; ++i)
	{
		fill_n(visited, 10001, false);
		BFS(i);
	}
	int maxElement = *max_element(hackNum.begin(), hackNum.end());
	for(int i = 1; i <= N; ++i)
	{
		if (hackNum[i] >= maxElement)
			cout << i << " ";
	}
}