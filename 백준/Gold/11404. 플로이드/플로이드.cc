#include <iostream>
#include <algorithm>

#define INF 1e9

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	int graph[101][101];
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		fill(graph[i], graph[i] + 101, INF);
	}

	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= n; ++b) {
			if (a == b)
			 graph[a][b] = 0;
		}
	}

	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a][b] = min(graph[a][b], c);
	}

	for (int k = 1; k <= n; ++k) {
		for (int a = 1; a <= n; ++a) {
			for (int b = 1; b <= n; ++b) {
				graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
			}
		}
	}

	for (int a = 1; a <= n; ++a) {
		for (int b = 1; b <= n; ++b) {
			if (graph[a][b] == INF)
				cout << 0 << " ";
			else
				cout << graph[a][b] << " ";
		}
		cout << endl;
	}
}