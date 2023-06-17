#include <string>
#include <vector>

using namespace std;


bool visited[200];
int answer = 0;

void dfs(int n, vector<vector<int>> computers, int index) {
    visited[index] = true;
    for (int i = 0; i < n; ++i) {
        if (index != i && computers[index][i] == 1 && visited[i] == false) {
            dfs(n, computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    fill_n(visited, n, false);
    for (int i = 0; i < n; ++i) {
        if (visited[i] == false) {
            dfs(n, computers, i);
            answer++;
        }
    }
    return answer;
}