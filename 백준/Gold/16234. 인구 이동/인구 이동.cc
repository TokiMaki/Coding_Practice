#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, L, R;
int A[50][50];
bool visited[50][50];

bool bfs(int x, int y)
{
	int finishCheck = true;
	queue<pair<int, int>> q;
	vector<pair<int, int>> v;
	int vSum = 0;
	q.emplace(x, y);
	v.emplace_back(x, y);
	vSum += A[y][x];
	int dirX[4] = { 1, 0, -1, 0 };
	int dirY[4] = { 0, 1, 0, -1 };
	while(!q.empty())
	{
		int nowX = q.front().first;
		int nowY = q.front().second;
		q.pop();
		for(int i = 0; i < 4; ++i)
		{
			int nextX = nowX + dirX[i];
			int nextY = nowY + dirY[i];
			int difference = abs(A[nowY][nowX] - A[nextY][nextX]);
			if (nextX < 0 || nextX >= N) continue;
			if (nextY < 0 || nextY >= N) continue;
			if (difference >= L
				&& difference <= R
				&& visited[nextY][nextX] == false)
			{
				visited[nextY][nextX] = true;
				q.emplace(nextX, nextY);
				v.emplace_back(nextX, nextY);
				vSum += A[nextY][nextX];
				finishCheck = false;
			}
		}
	}
	vSum /= v.size();
	for(pair<int, int> p : v)
	{
		int x = p.first;
		int y = p.second;
		A[y][x] = vSum;
	}
	return finishCheck;
}

int main() {
	int answer = 0;
	cin >> N >> L >> R;
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			cin >> A[i][j];
		}
	}
	int finishCheck = true;
	while (true) {
		finishCheck = true;
		for (int i = 0; i < N; ++i)
		{
			fill_n(visited[i], N, false);
		}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (visited[i][j] == false)
				{
					visited[i][j] = true;
					if (bfs(j, i) == false)
						finishCheck = false;
				}
			}
		}
		if (finishCheck == false) {
			answer++;
		}
		else
			break;
	}
	cout << answer;
}