#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int parent[1000001];

int findParent(int x)
{
	if (parent[x] == x)
		return x;
	return parent[x] = findParent(parent[x]);
}

void unionParent(int a, int b)
{
	a = findParent(a);
	b = findParent(b);

	if (a == b)
		return;

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i <= n; ++i)
	{
		parent[i] = i;
	}
	for(int i = 0; i < m; ++i)
	{
		int commend, a, b;
		cin >> commend >> a >> b;
		if (commend == 0)
		{
			if (findParent(a) != findParent(b))
				unionParent(a, b);
		}
		else if (commend == 1)
		{
			if (findParent(a) == findParent(b))
			{
				cout << "YES" << "\n";
			}
			else
			{
				cout << "NO" << "\n";
			}
		}
	}
}