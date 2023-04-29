#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int graph[25][25];
vector<int> complex;
int visited[25][25] = { 0, };
int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };
int cnt = 0;

void dfs(int num, int x, int y)
{
	cnt++;
	visited[y][x] = num;

	for(int i = 0; i < 4; ++i)
	{
		int nextx = x + dir_x[i];
		int nexty = y + dir_y[i];
		if ((nextx >= 0 && nextx < 25) && (nexty >= 0 && nexty < 25)) {
			if (visited[nexty][nextx] == 0 && graph[nexty][nextx] == 1)
				dfs(num, nextx, nexty);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; ++j)
		{
			graph[i][j] = tmp[j] - '0';
		}
	}

	int num = 0;

	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (visited[i][j] == 0 && graph[i][j] == 1) {
				cnt = 0;
				dfs(++num, j, i);
				complex.push_back(cnt);
			}
		}
	}

	sort(complex.begin(), complex.end());

	cout << complex.size() << "\n";
	for (int i : complex)
		cout << i << "\n";
}