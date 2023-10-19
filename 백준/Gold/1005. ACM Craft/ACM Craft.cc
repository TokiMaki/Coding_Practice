#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int T, N, K, W;
int dp[1001];
int techs[1001];
vector<int> times;

void bfs(vector<vector<int>> graphs)
{
	queue<int> q;

	for(int i = 1; i <= N; ++i)
	{
		if (techs[i] == false)
		{
			q.push(i);
			dp[i] = times[i - 1];
		}
	}

	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i : graphs[now]) {
			techs[i]--;
			dp[i] = max(dp[i], dp[now] + times[i - 1]);
			if (techs[i] == 0)
				q.push(i);
		}
	}
}

int main()
{
	int answer;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N >> K;
		vector<vector<int>> graphs(N + 1);
		times.clear();
		fill_n(dp, N + 1, 0);
		fill_n(techs, N + 1, 0);
		for (int j = 0; j < N; ++j)
		{
			int time;
			cin >> time;
			times.push_back(time);
		}

		for (int j = 0; j < K; ++j)
		{
			int s, e;
			cin >> s >> e;
			graphs[s].push_back(e);
			techs[e]++;
		}

		cin >> W;
		
		bfs(graphs);

		cout << dp[W] << "\n";
	}
}