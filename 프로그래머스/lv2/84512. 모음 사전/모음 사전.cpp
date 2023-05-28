#include <string>
#include <vector>

using namespace std;

int answer = 0;
bool check = false;
string dic = "AEIOU";

void dfs(string word, string next){
    if (check)
        return;
    if (word == next) {
        check = true;
        return;
    }
    if (next.length() >= 5)
        return;
    for(int i = 0; i < 5; ++i) {
        if (check == false) {
            answer++;
            dfs(word, next + dic[i]);
        }
    }
}

int solution(string word) {
    dfs(word, "");
    return answer;
}