#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for(string s : participant)
    {
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