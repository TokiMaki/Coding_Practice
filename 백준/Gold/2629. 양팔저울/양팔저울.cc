#include <iostream>
#include <cmath>

using namespace std;

int weight[31];
bool dp[31][15001];
int N, M;

void solve(int i, int w)
{
	if (i > N || dp[i][w])
		return;
	dp[i][w] = true;
	solve(i + 1, w + weight[i]);
	solve(i + 1, abs(w - weight[i]));
	solve(i + 1, w);
}

int main()
{
	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		cin >> weight[i];
	}

	solve(0, 0);

	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int tmp;
		cin >> tmp;
		if (tmp > 15000)
			cout << "N" << " ";
		else if (dp[N][tmp])
			cout << "Y" << " ";
		else
			cout << "N" << " ";
	}
}