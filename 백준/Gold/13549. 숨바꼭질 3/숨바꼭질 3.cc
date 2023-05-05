#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

bool visited[100001];
int N, K;


int dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	visited[start] = true;
	while(!pq.empty())
	{
		int curr_time = pq.top().first;
		int curr_start = pq.top().second;
		pq.pop();

		if (curr_start == K)
			return curr_time;

		int next_start = curr_start * 2;
		if (next_start <= 100000) {
			if (visited[next_start] == false)
			{
				visited[next_start] = true;
				pq.push({ curr_time, next_start });
			}
		}

		next_start = curr_start + 1;
		if (next_start <= 100000) {
			if (visited[next_start] == false)
			{
				visited[next_start] = true;
				pq.push({ curr_time + 1, next_start });
			}
		}

		next_start = curr_start - 1;
		if (next_start >= 0) {
			if (visited[next_start] == false)
			{
				visited[next_start] = true;
				pq.push({ curr_time + 1, next_start });
			}
		}

	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	cout << dijkstra(N);
}