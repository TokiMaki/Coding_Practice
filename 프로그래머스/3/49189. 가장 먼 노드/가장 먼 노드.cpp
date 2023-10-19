#include <string>
#include <vector>
#include <queue>

using namespace std;

int dp[20001] = { 0, };

void dijkstra(int node, vector<vector<int>> graphs) {
    dp[node] = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(1, node);
    while(!pq.empty()) {
        int now_cost = pq.top().first;
        int now_node = pq.top().second;
        pq.pop();
        for(int graph : graphs[now_node]) {
            if (dp[graph] == 0 || dp[graph] > now_cost + 1) {
                dp[graph] = now_cost + 1;
                pq.emplace(dp[graph], graph);
            }
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    int maxelement = 0;
    vector<vector<int>> graphs(n + 1);
    for(vector<int> v : edge) {
        graphs[v[0]].push_back(v[1]);
        graphs[v[1]].push_back(v[0]);
    }
    dijkstra(1, graphs);
    for(int i = 1; i <= n; ++i) {
        maxelement = max(maxelement, dp[i]);
    }
    for(int i = 1; i <= n; ++i) {
        if (maxelement == dp[i])
            answer++;
    }
        
    return answer;
}