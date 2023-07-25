#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2);
    priority_queue <int, vector<int>> maxPq;
    priority_queue <int, vector<int>, greater<int>> minPq;
    
    for(string operation : operations) {
        stringstream ss;
        ss.str(operation);
        string commend;
        ss >> commend;
        int num;
        ss >> num;
        switch(commend[0]) {
            case 'I' :
                maxPq.push(num);
                minPq.push(num);
                break;
            case 'D' :
                if (num == 1) {
                    if (!maxPq.empty())
                        maxPq.pop();
                }
                if (num == -1) {
                    if (!minPq.empty())
                        minPq.pop();
                }
                break;
        }
        if (maxPq.empty()) {
            while(!minPq.empty())
                minPq.pop();
        }
        else if (minPq.empty()) {
            while(!maxPq.empty())
                maxPq.pop();
        }
        else if (minPq.top() > maxPq.top()) {
            while(!minPq.empty())
                minPq.pop();
            while(!maxPq.empty())
                maxPq.pop();
        }
    }
    if (!maxPq.empty())
        answer[0] = maxPq.top();
    if (!minPq.empty())
        answer[1] = minPq.top();

    return answer;
}