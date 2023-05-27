#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<pair<int, int>> v;
    int sum = brown + yellow;
    for(int i = 3; i <= sqrt(sum); ++i){
        if (sum / i * i == sum)
            v.emplace_back(sum / i, i);
    }
    for(pair<int, int> p : v) {
        if ((p.first * 2 + p.second * 2 - 4) <= brown){
            answer.push_back(p.first);
            answer.push_back(p.second);
            break;
        }
    }
    return answer;
}