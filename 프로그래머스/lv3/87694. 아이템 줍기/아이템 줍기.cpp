#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int visited[51][51] = { 0, };
int dir_x[4] = { 1, 0, -1, 0 };
int dir_y[4] = { 0, 1, 0, -1 };
int answer = 0;

bool collision(vector<vector<int>> rectangle, float characterX, float characterY) {
    for (vector<int> v : rectangle) {
        if ((float)v[0] < characterX && (float)v[2] > characterX
            && (float)v[1] < characterY && (float)v[3] > characterY)
            return true;
    }
    for (vector<int> v : rectangle) {
        if ((float)v[0] <= characterX && (float)v[2] >= characterX
            && (float)v[1] <= characterY && (float)v[3] >= characterY)
            return false;
    }
    return true;
}

void bfs(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    queue<pair<int, int>> q;
    q.emplace(characterX, characterY);
    for (int i = 0; i < 51; ++i) {
        fill_n(visited[i], 51, -1);
    }
    visited[characterY][characterX] = 0;
    while (!q.empty()) {
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();
        if (now_x == itemX && now_y == itemY) {
            answer = visited[now_y][now_x];
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int next_x = now_x + dir_x[i];
            if (next_x < 1 || next_x > 50)
                continue;
            int next_y = now_y + dir_y[i];
            if (next_y < 1 || next_y > 50)
                continue;
            if (collision(rectangle, next_x - dir_x[i] * 0.5f, next_y - dir_y[i] * 0.5f) == false
                && visited[next_y][next_x] == -1) {
                visited[next_y][next_x] = visited[now_y][now_x] + 1;
                q.emplace(next_x, next_y);
            }
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    bfs(rectangle, characterX, characterY, itemX, itemY);
    return answer;
}
