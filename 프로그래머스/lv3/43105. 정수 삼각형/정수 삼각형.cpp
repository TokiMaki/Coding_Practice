#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> dp(triangle.size());
    dp[0].push_back(triangle[0][0]);
    for(int i = 1; i < triangle.size(); ++i) {
        for(int j = 0; j < triangle[i].size(); ++j) {
            int left = 0, right = 0;
            if (j - 1 >= 0)
                left = dp[i - 1][j - 1] + triangle[i][j];
            if (j < triangle[i].size() - 1)
                right = dp[i - 1][j] + triangle[i][j];
            dp[i].push_back(max(left, right));
        }
    }
    answer = *max_element(dp[triangle.size() - 1].begin(), dp[triangle.size() - 1].end());
    return answer;
}
