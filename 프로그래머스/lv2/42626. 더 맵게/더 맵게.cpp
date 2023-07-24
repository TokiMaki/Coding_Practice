#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> p_q;
    for(int i : scoville)
        p_q.push(i);
    while(p_q.top() < K && p_q.size() >= 2) {
        int firstFood = p_q.top();
        p_q.pop();
        int secondFood = p_q.top();
        p_q.pop();
        int newFood = firstFood + secondFood * 2;
        p_q.push(newFood);
        answer++;
    }
    if (p_q.top() < K)
        answer = -1;
    return answer;
}