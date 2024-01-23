#include <iostream>
#include <vector>

using namespace std;

int N, S, answer;
vector<int> v;
bool visited[20];

void Dfs(int start, int sumNum)
{
	if (sumNum == S)
		answer++;
	for (int i = start; i < N; ++i)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			Dfs(i + 1, sumNum + v[i]);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;
	answer = 0;
	fill_n(visited, N, false); 
	for(int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	for(int i = 0; i < N; ++i)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			Dfs(i + 1, v[i]);
			visited[i] = false;
		}
	}

	cout << answer;
}