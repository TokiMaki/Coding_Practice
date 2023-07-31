#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parant[100];

int findparant(int x) {
    if (parant[x] == x)
        return x;
    return parant[x] = findparant(parant[x]);
}

void unionparant(int a, int b) {
    a = findparant(a);
    b = findparant(b);
    
    if (a < b)
        parant[b] = a;
    else
        parant[a] = b;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 0; i < 100; ++i)
        parant[i] = i;
    
    sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b){
        return a[2] < b[2];
    });
    
    for(vector<int> cost : costs) {
        if (findparant(cost[0]) != findparant(cost[1])) {
            unionparant(cost[0], cost[1]);
            answer += cost[2];
        }
    }
    
    return answer;
}