#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = -1;
    vector<unordered_set<int>> dp(9);
    for(int i = 1; i <= 8; ++i) {
        string tmp;
        int NN = 0;
        for(int j = 0; j < i; ++j) {
            tmp += to_string(N);
        }
        NN = stoi(tmp);
        dp[i].insert(NN);
        for(int j = 1; j <= i; ++j) {
            int k = i - j;
            if (k > 0) {
                for(int a : dp[j]) {
                    for(int b : dp[k]) {
                        dp[i].insert(a + b);
                        if (a - b > 0)
                            dp[i].insert(a - b);
                        dp[i].insert(a * b);
                        if (a / b > 0)
                            dp[i].insert(a / b);
                    }
                }
            }
        }
        if (dp[i].find(number) != dp[i].end()){
            answer = i;
            break;
        }
    }
    return answer;
}