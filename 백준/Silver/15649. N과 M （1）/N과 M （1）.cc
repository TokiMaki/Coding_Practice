#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int num[8];
int visited[9];
void dfs(int cnt)
{
	if (cnt >= M) {
		for (int i = 0; i < M; ++i)
		{
			cout << num[i] << " ";
		}
		cout << "\n";
		return;
	}

	for(int i = 1; i <= N; ++i)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			num[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;

	fill_n(visited, 8, false);
	dfs(0);
}