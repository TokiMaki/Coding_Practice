#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

bool visited[101];
vector<int> grahp[101];

int bfs(int start) {
    queue<int> q;
    q.push(start);
    int returnValue = 1;
    if (visited[start] == true)
        return -1;
    visited[start] = true;
    while(!q.empty()) {
        int next = q.front();
        q.pop();
        returnValue++;
        for(int i : grahp[next]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    return returnValue;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;
    
    for(vector<int> v : wires) {
        grahp[v[0]].push_back(v[1]);
        grahp[v[1]].push_back(v[0]);
    }
    
    for (int i = 0; i < n - 1; ++i) {
        fill_n(visited, 101, false);
        grahp[wires[i][0]].erase(remove(grahp[wires[i][0]].begin(), 
                                        grahp[wires[i][0]].end(), wires[i][1]), grahp[wires[i][0]].end());
        grahp[wires[i][1]].erase(remove(grahp[wires[i][1]].begin(), 
                                        grahp[wires[i][1]].end(), wires[i][0]), grahp[wires[i][1]].end());
        int connectnum[2] = { 0, 0 };
        connectnum[0] = bfs(wires[i][0]);
        connectnum[1] = bfs(wires[i][1]);
        if (connectnum[0] != -1 && connectnum[1] != -1)
            answer = min(answer, abs(connectnum[0] - connectnum[1]));
        grahp[wires[i][0]].push_back(wires[i][1]);
        grahp[wires[i][1]].push_back(wires[i][0]);
    }
    
    return answer;
}