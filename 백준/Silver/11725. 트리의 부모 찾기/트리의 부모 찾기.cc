#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[100001];
bool visited[100001];
int parent[100001];

void bfs(vector<int> v[])
{
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		for(int i : v[now])
		{
			if (visited[i] == false)
			{
				parent[i] = now;
				q.push(i);
				visited[i] = true;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	fill_n(visited, 100001, false);
	for(int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	bfs(v);
	for(int i = 2; i <= n; ++i)
	{
		cout << parent[i] << "\n";
	}
}