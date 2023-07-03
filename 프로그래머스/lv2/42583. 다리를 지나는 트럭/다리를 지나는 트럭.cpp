#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> q;
    queue<int> bridge_q;

    for (int i : truck_weights) {
        q.push(i);
    }
    for (int i = 0; i < bridge_length; ++i) {
        bridge_q.push(0);
    }

    int bridgeWeight = 0;
    int cnt = 0;
    int complete = 0;

    while (complete < truck_weights.size()) {
        int bridgeTruckWeight = bridge_q.front();
        bridgeWeight -= bridgeTruckWeight;
        if (bridgeTruckWeight > 0)
            complete++;
        bridge_q.pop();

        int truckWeight = 0;

        if (!q.empty())
    		truckWeight = q.front();
    	if (bridgeWeight + truckWeight <= weight && truckWeight != 0) {
    		bridge_q.push(truckWeight);
    		bridgeWeight += truckWeight;
    		q.pop();
    	}
        else {
            bridge_q.push(0);
        }

        cnt++;
    }
    answer = cnt;
    return answer;
}