#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> m;
    
    for(string s : participant)
    {
        if (m.end() == m.find(s))
            m.insert({s, 1});
        else
            m[s]++;
    }
    
    for(string s : completion)
    {
        m[s]--;
    }
    
    for(auto a = m.begin(); a != m.end(); ++a)
    {
        if (a->second > 0){
            answer = a->first;
            break;
        }
    }
    
    return answer;
}