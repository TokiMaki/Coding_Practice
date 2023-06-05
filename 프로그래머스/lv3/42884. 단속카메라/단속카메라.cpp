#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> parent(60001);

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b) {
        if (a[0] == b[0])
            return a[1] < b[1];
        return a[0] < b[0];
        });

    int beforeend = routes[0][1];
    for (int i = 1; i < routes.size(); ++i) {
        if (beforeend < routes[i][0])
        {
            answer++;
            beforeend = routes[i][1];
        }
        else if (beforeend >= routes[i][1])
        {
            beforeend = routes[i][1];
        }
    }
    return answer;
}