#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> closeletter;
    for (int i = 0; i < s.length(); ++i) {
        auto result = closeletter.insert(pair<char, int>(s[i], i));
        if (result.second == true)
            answer.push_back(-1);
        else {
            answer.push_back(i - result.first->second);
            result.first->second = i;
        }
    }
    return answer;
}