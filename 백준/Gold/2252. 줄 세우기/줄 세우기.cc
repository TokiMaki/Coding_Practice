#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dgrees[32001] = {0, };
int N, M;
vector<vector<int>> graphs(32001);
vector<int> answer;

void bfs()
{
	queue<int> q;

	for (int i = 1; i <= N; ++i)
	{
		if (dgrees[i] == 0) {
			q.push(i);
		}
	}

	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		answer.push_back(now);
		for(int i : graphs[now])
		{
			dgrees[i]--;
			if (dgrees[i] == 0)
				q.push(i);
		}
	}
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		graphs[a].push_back(b);
		dgrees[b]++;
	}

	bfs();

	for(int i : answer)
	{
		cout << i << " ";
	}
}