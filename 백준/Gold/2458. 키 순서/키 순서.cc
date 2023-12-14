#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#define INF 1<<20
using namespace std;

int d[501][501];

int main() {
	int N, M;
	int answer = 0;
	cin >> N >> M;
	
	for (int i = 0; i < 501; ++i) {
		fill_n(d[i], 501, INF);
	}
	for(int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
		d[b][a] = 0;
	}

	for(int m = 1; m <= N; ++m)
	{
		for(int s = 1; s <= N; ++s)
		{
			for(int e = 1; e <= N; ++e)
			{
				if (d[e][s] == 0 || (d[s][m] == 1 && d[m][e] == 1)) {
					d[e][s] = 0;
					d[s][e] = 1;
				}
			}
		}
	}

	for(int i = 1; i <= N; ++i)
	{
		int cnt = 0;
		for (int j = 1; j <= N; ++j)
		{
			if (i == j)
				continue;
			if (d[i][j] != INF)
				cnt++;
		}
		if (cnt == N - 1)
			answer++;
	}

	cout << answer;
}