#include <string>
#include <vector>
#include <queue>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p_q;
    auto comp = [](pair<int, int> a, pair<int, int> b){ return a.second > b.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> timep_q(comp);
    for(vector<int> job : jobs)
        p_q.emplace(job[0], job[1]);
    int now = 0;
    while(!p_q.empty() || !timep_q.empty()) {
        if (!p_q.empty()) {
            pair<int, int> job = p_q.top();
            if (now >= job.first) {
                timep_q.push(job);
                p_q.pop();
                continue;
            }
        }
        if (!timep_q.empty()) {
            pair<int, int> job = timep_q.top();
            now += job.second;
            answer += now - job.first;
            timep_q.pop();
        }
        else {
            pair<int, int> job = p_q.top();
            now = job.first;
        }
    }
    return answer / jobs.size();
}