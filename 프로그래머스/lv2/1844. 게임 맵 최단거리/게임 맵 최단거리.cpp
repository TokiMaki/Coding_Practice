#include<vector>
#include <queue>
using namespace std;

int answer = -1;
int visited[100][100] = {1, };
int dir_x[4] = {1, 0, -1, 0};
int dir_y[4] = {0, 1, 0, -1};

void bfs(vector<vector<int>> maps, int x, int y, int num) {
    int n = maps.size();
    int m = maps[0].size();
    
    queue<pair<pair<int, int>, int>> q;
    visited[y][x] = num;
    q.push({{x, y}, num});
    
    while(!q.empty()) {
        int now_x = q.front().first.first;
        int now_y = q.front().first.second;
        int now_num = q.front().second;
        q.pop();
        if (now_x == m - 1 && now_y == n - 1) {
            if (answer != -1)
                answer = min(answer, now_num);
            else
                answer = now_num;
            return;
        }
        for(int i = 0; i < 4; ++i) {
            int next_x = now_x + dir_x[i];
            if (next_x >= m || next_x < 0)
                continue;
            int next_y = now_y + dir_y[i];
            if (next_y >= n || next_y < 0)
                continue;
            if (maps[next_y][next_x] == 1) {
                if (visited[next_y][next_x] == 0 || now_num + 1 < visited[next_y][next_x]) {
                    q.push({{next_x, next_y}, now_num + 1});
                    visited[next_y][next_x] = now_num + 1;
                }
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    bfs(maps, 0, 0, 1);
    return answer;
}