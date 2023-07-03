#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> p_q;
    
    for(int i = 0; i < priorities.size(); ++i) {
        q.emplace(priorities[i], i);
        p_q.push(priorities[i]);
    }
    
    int cnt = 1;
    while(!q.empty()) {
        int priority = q.front().first;
        int num = q.front().second;
        q.pop();
        int maxpriority = p_q.top();
        if (priority >= maxpriority) {
            if (num == location) {
                answer = cnt;
                break;
            }
            else {
                p_q.pop();
                cnt++;
            }   
        }
        else
            q.emplace(priority, num);
    }
    
    return answer;
}