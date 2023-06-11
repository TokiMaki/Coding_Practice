#include <string>
#include <vector>

using namespace std;

int dp[101][101] = { 0, };

void dfs(int x, int y, int m, int n){
    if(x + 1 <= m && dp[y][x + 1] != -1) {
        dp[y][x + 1]++;
        dfs(x + 1, y, m, n);
    }
    if (y + 1 <= n && dp[y + 1][x] != -1) {
        dp[y + 1][x]++;
        dfs(x, y + 1, m, n);
    }
}

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(vector<int> v : puddles) {
        dp[v[1]][v[0]] = -1;
    }
    dp[1][1] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if (dp[i][j] == -1) continue;
            if(j - 1 > 0 && dp[i][j - 1] != -1) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % 1000000007;
            }
            if (i - 1 > 0 && dp[i - 1][j] != -1) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % 1000000007;
            }
        }
    }
    answer = dp[n][m];
    return answer;
}