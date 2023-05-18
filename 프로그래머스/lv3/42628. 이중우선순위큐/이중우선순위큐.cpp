#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    priority_queue<int, vector<int>> max_pq;

    for (string s : operations) {
        stringstream stream;
        stream.str(s);
        char type;
        int num;
        stream >> type;
        if (type == 'I') {
            stream >> num;
            min_pq.push(num);
            max_pq.push(num);
        }
        if (type == 'D') {
            stream >> num;
            if (num == 1) {
                if (!max_pq.empty()) {
                    max_pq.pop();
                }
            }
            else if (num == -1) {
                if (!min_pq.empty()) {
                    min_pq.pop();
                }
            }
        }

        while (!max_pq.empty()) {
            if (min_pq.empty()) {
                max_pq.pop();
                continue;
            }
            if (!min_pq.empty())
            {
                if (min_pq.top() > max_pq.top())
                {
                    max_pq.pop();
                }
                else
                    break;
            }
        }

        while (!min_pq.empty()) {
            if (max_pq.empty()) {
                min_pq.pop();
                continue;
            }
            if (!max_pq.empty())
            {
                if (min_pq.top() > max_pq.top())
                {
                    min_pq.pop();
                }
                else
                    break;
            }
        }
    }

    if (!max_pq.empty())
        answer.push_back(max_pq.top());
    else
        answer.push_back(0);
    if (!min_pq.empty())
        answer.push_back(min_pq.top());
    else
        answer.push_back(0);

    return answer;
}