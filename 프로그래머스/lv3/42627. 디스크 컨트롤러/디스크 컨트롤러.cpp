#include <string>
#include <vector>
#include <queue>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second > b.second;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    priority_queue <pair<int, int>, vector<pair<int, int>>, decltype(&comp)> time_pq(comp);
    for (auto a : jobs)
        pq.emplace(a[0], a[1]);
    int now = 0;
    while (!pq.empty() || !time_pq.empty()) {
        int wait = pq.top().first;
        int volume = pq.top().second;
        if (!pq.empty() && wait <= now) {
            time_pq.emplace(wait, volume);
            pq.pop();
            continue;
        }
        if (!time_pq.empty()) {
            int timewait = time_pq.top().first;
            int timevolume = time_pq.top().second;
            now += timevolume;
            answer += now - timewait;
            time_pq.pop();
        }
        else {
            now = wait;
        }
    }
    return answer / jobs.size();
}