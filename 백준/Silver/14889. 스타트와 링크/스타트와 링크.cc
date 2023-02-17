#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int S[20][20] = { };
bool team[20] = { };
int N;
int Min = 1000000000;

void dfs(int idx, int cnt) {
	vector<int> startteam;
	vector<int> linkteam;
	int team1 = 0, team2 = 0;

	if (cnt >= (N / 2)) {
		for (int i = 0; i < N; ++i) {
			if (team[i] == true)
				startteam.push_back(i);
			else
				linkteam.push_back(i);
		}
		for (int i = 0; i < (N / 2); ++i) {
			for (int j = 0; j < (N / 2); ++j) {
				team1 += S[startteam[i]][startteam[j]];
				team2 += S[linkteam[i]][linkteam[j]];
			}
		}
		int diff = abs(team1 - team2);
		if (Min > diff) {
			Min = diff;
		}
		return;
	}

	for (int i = idx; i < N; ++i) {
		if (team[i] == true)
			continue;
		else {
			team[i] = true;
			dfs(i, cnt + 1);
			team[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> N;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> S[i][j];
		}
	}

	dfs(0, 0);
	cout << Min;
}