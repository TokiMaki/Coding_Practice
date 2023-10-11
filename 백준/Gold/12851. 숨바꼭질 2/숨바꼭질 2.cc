#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int answer = 0;
int N, K;
int shortTime = INT_MAX;

int visited[100001];

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
			if (shortTime > cnt) {
				shortTime = cnt;
				answer = 0;
			}
			answer++;
		}

		if (now - 1 >= 0) {
			if (visited[now - 1] >= cnt + 1) {
				visited[now - 1] = cnt + 1;
				p.emplace(cnt + 1, now - 1);
			}
		}
		if (now + 1 <= 100000) {
			if (visited[now + 1] >= cnt + 1) {
				visited[now + 1] = cnt + 1;
				p.emplace(cnt + 1, now + 1);
			}
		}

		if (now * 2 <= 100000) {
			if (visited[now * 2] >= cnt + 1) {
				visited[now * 2] = cnt + 1;
				p.emplace(cnt + 1, now * 2);
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	fill_n(visited, 100001, INT_MAX);
	bfs();
	if (shortTime == INT_MAX)
		shortTime = 0;
	cout << shortTime << "\n";
	cout << answer;
}