#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int N, K;

int visited[100001];

int bfs()
{
	queue<pair<int, int>> p;
	
	p.emplace(0, N);
	while(!p.empty())
	{
		int cnt = p.front().first;
		int now = p.front().second;
		p.pop();
		if (now == K)
			return cnt;

		if (now - 1 >= 0) {
			if (visited[now - 1] > cnt) {
				visited[now - 1] = cnt;
				p.emplace(cnt + 1, now - 1);
			}
		}
		if (now + 1 <= 100000) {
			if (visited[now + 1] > cnt) {
				visited[now + 1] = cnt;
				p.emplace(cnt + 1, now + 1);
			}
		}

		if (now * 2 <= 100000) {
			if (visited[now * 2] > cnt) {
				visited[now * 2] = cnt;
				p.emplace(cnt + 1, now * 2);
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	fill_n(visited, 100001, INT_MAX);
	cout << bfs();
}