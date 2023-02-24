#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][1001];

int main() {
	vector<string> v;

	for (int i = 0; i < 2; ++i) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	for (int i = 1; i <= v[0].length(); ++i) {
		for (int j = 1; j <= v[1].length(); ++j) {
			if (v[0][i - 1] == v[1][j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	
	cout << dp[v[0].length()][v[1].length()];
}