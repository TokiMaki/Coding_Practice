#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

#define INF 200000001

using namespace std;

int N;
int graph[125][125];
int d[125][125];

void dijkstra(int start)
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			d[i][j] = INF;
		}
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	d[start / N][start % N] = graph[start / N][start % N];
	pq.push({ d[start / N][start % N] , start });

	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	while (!pq.empty()) {
		int topcost = pq.top().first;
		int nowx = pq.top().second % N;
		int nowy = pq.top().second / N;
		pq.pop();
		for (int i = 0; i < 4; ++i) {
			int nextx = nowx + dx[i];
			if (nextx < 0 || nextx >= N)
				continue;
			int nexty = nowy + dy[i];
			if (nexty < 0 || nexty >= N)
				continue;
			int nextcost = graph[nextx][nexty] + topcost;
			if (d[nexty][nextx] > nextcost) {
				d[nexty][nextx] = nextcost;
				pq.push({ nextcost, nexty * N + nextx });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int count = 0;
	while (true) {
		cin >> N;

		if (N == 0)
			break;
		count++;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> graph[i][j];
			}
		}
		dijkstra(0);

		cout << "Problem " << count << ": " << d[N - 1][N - 1] << endl;
	}
}