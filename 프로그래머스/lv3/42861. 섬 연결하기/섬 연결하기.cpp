#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[100];

int findparent(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = findparent(parent[x]);
}

int unionparent(int a, int b) {
    a = findparent(a);
    b = findparent(b);
    if (a < b)
        return parent[b] = a;
    else
        return parent[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for(int i = 0; i < 100; ++i) { 
        parent[i] = i;
    }
    
    sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b){
        return a[2] < b[2];
    });
    
    for(vector<int> cost : costs) {
        if (findparent(cost[0]) != findparent(cost[1])) {
            unionparent(cost[0], cost[1]);
            answer += cost[2];
        }
    }
    
    return answer;
}