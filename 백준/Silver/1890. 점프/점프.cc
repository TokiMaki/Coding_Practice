#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long  gameBoard[100][100];
long long  dp[100][100];
long long  N;

void bfs()
{
	queue<pair<long long, long long >> q;
	q.emplace(0, 0);

	long long  dirX[2] = { 1, 0 };
	long long  dirY[2] = { 0, 1 };

	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			long long  nowX = j;
			long long  nowY = i;
			long long  jumpNum = gameBoard[nowY][nowX];
			if (jumpNum == 0 || dp[nowY][nowX] == 0)
				continue;
			for(int k = 0; k < 2; ++k)
			{
				long long  nextX = nowX + jumpNum * dirX[k];
				long long  nextY = nowY + jumpNum * dirY[k];
				if (nextX >= N || nextX < 0
					|| nextY >= N || nextY < 0)
					continue;
				dp[nextY][nextX] += dp[nowY][nowX];
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j) {
			cin >> gameBoard[i][j];
		}
	}
	for (int i = 0; i < N; ++i)
	{
		fill_n(dp[i], N, 0);
	}
	dp[0][0] = 1;

	bfs();

	cout << dp[N - 1][N - 1];
}