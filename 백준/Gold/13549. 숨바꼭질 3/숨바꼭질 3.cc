#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

int answer = 0;
int N, K;
int shortTime = INT_MAX;

int visited[100001];

int bfs()
{
	deque<pair<int, int>> p;
	
	p.emplace_back(0, N);
	visited[N] = 0;
	while(!p.empty())
	{
		int cnt = p.front().first;
		int now = p.front().second;
		p.pop_front();

		if (now == K)
		{
			return cnt;
		}

		if (now * 2 <= 100000) {
			if (visited[now * 2] > cnt) {
				visited[now * 2] = cnt;
				p.emplace_front(cnt, now * 2);
			}
		}
		if (now - 1 >= 0) {
			if (visited[now - 1] > cnt + 1) {
				visited[now - 1] = cnt + 1;
				p.emplace_back(cnt + 1, now - 1);
			}
		}
		if (now + 1 <= 100000) {
			if (visited[now + 1] > cnt + 1) {
				visited[now + 1] = cnt + 1;
				p.emplace_back(cnt + 1, now + 1);
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	fill_n(visited, 100001, INT_MAX);
	answer = bfs();
	cout << answer;
}