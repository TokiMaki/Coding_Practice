#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> q;
    for(int i = 0; i < progresses.size(); ++i)
        q.emplace(progresses[i], speeds[i]);
    int day = 1;
    int cnt = 0;
    while(!q.empty()) {
        int progress = q.front().first;
        int speed = q.front().second;
        progress += day * speed;
        if (progress >= 100) {
            cnt++;
            q.pop();
        }
        else {
            if (cnt >= 1) {
                answer.push_back(cnt);
                cnt = 0;
            }
            else
                day++;
        }
    }
    if (cnt >= 1) {
        answer.push_back(cnt);
    }
    
    return answer;
}