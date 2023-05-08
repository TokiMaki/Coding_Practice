#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> map;
    for(vector<string> v : clothes){
        map[v[1]]++;
    }
    
    for(auto a = map.begin(); a != map.end(); ++a){
        answer *= a->second + 1;
    }
    return answer - 1;
}