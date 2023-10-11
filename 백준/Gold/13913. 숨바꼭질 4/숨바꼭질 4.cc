#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int answer = 0;
int N, K;
int shortTime = INT_MAX;

int visited[200001];
int parent[200001];

void bfs()
{
	queue<pair<int, int>> p;
	
	p.emplace(0, N);
	visited[N] = 0;
	while(!p.empty())
	{
		int cnt = p.front().first;
		int now = p.front().second;
		p.pop();

		if (now == K)
		{
			cout << cnt << "\n";
			vector<int> path;
			while(now != N)
			{
				path.push_back(now);
				now = parent[now];
			}
			path.push_back(now);
			for(auto it = path.rbegin(); it != path.rend(); ++it)
			{
				cout << *it << " ";
			}
			return;
		}


		if (now - 1 >= 0) {
			if (visited[now - 1] > cnt + 1) {
				visited[now - 1] = cnt + 1;
				parent[now - 1] = now;
				p.emplace(cnt + 1, now - 1);
			}
		}

		if (now + 1 <= 200000) {
			if (visited[now + 1] > cnt + 1) {
				visited[now + 1] = cnt + 1;
				parent[now + 1] = now;
				p.emplace(cnt + 1, now + 1);
			}
		}

		if (now * 2 <= 200000) {
			if (visited[now * 2] > cnt) {
				visited[now * 2] = cnt;
				parent[now * 2] = now;
				p.emplace(cnt + 1, now * 2);
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	fill_n(visited, 200001, INT_MAX);
	bfs();
}