#include <string>
#include <vector>

using namespace std;
int answer = 0;
bool visited[8];
void dfs(vector<vector<int>> dungeonsm, int k, int num) {
    if (answer >= dungeonsm.size())
        return;
    for(int i = 0; i < dungeonsm.size(); ++i) {
        if (k >= dungeonsm[i][0] && visited[i] == false) {
            visited[i] = true;
            answer = max(answer, num + 1);
            dfs(dungeonsm, k - dungeonsm[i][1], num + 1);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(dungeons, k, 0);
    return answer;
}