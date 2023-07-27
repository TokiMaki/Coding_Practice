#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    
    while(true){
        if (distance(lower_bound(citations.begin(), citations.end(), answer), citations.end()) >= answer)
            answer++;
        else {
            answer--;
            break;
        }
    }
    return answer;
}