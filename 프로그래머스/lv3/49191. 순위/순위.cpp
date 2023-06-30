#include <string>
#include <vector>

using namespace std;

int score[101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    fill_n(score, n + 1, 1);
    vector<vector<int>> graphs(n + 1);
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= n; ++j)
            graphs[i].push_back(0);
    }
    for(vector<int> result : results) {
        graphs[result[0]][result[1]] = 1;
    }
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if (graphs[i][j] == 0 && graphs[i][k] == 1 && graphs[k][j] == 1) {
                    graphs[i][j] = 1;
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        int cnt = 0;
        for(int j = 1; j <= n; ++j) {
            if (graphs[i][j] == 1 || graphs[j][i] == 1)
                cnt++;
        }
        if (cnt == n - 1)
            answer++;
    }
    return answer;
}