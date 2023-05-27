#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> person{{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
    vector<int> answernum = {0, 0, 0};
    
    for(int i = 0; i < answers.size(); ++i) {
        for(int j = 0; j < 3; ++j) {
            if (answers[i] == person[j][i % person[j].size()])
                answernum[j]++;
        }
    }
    
    int answermax = *max_element(answernum.begin(), answernum.end());
    
    for(int i = 0; i < answernum.size(); ++i){
        if (answermax == answernum[i])
            answer.push_back(i + 1);
    }
    return answer;
}