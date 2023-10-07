#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;

    for (int i : truck_weights) {
        q.push(i);
    }
    
    queue<int> bridge_q;
    
    for(int i = 0; i < bridge_length; ++i) {
        bridge_q.push(0);
    }
    
    int complete = 0;
    int bridgeWeight = 0;
    
    while(complete < truck_weights.size()) {
        int frontBridgeTruck = bridge_q.front();
        bridge_q.pop();
        
        if (frontBridgeTruck != 0) {
            complete++;
            bridgeWeight -= frontBridgeTruck;
        }
        
        int qTruckWeight = 0;
        
        if (!q.empty())
            qTruckWeight = q.front();
        
        if (bridgeWeight + qTruckWeight <= weight && qTruckWeight != 0) {
            bridge_q.push(q.front());
            bridgeWeight += q.front();
            q.pop();
        }
        else
            bridge_q.push(0);
        
        answer++;
    }
    
    return answer;
}