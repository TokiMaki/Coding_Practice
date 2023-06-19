#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int answer = 0;
int visited[50];

void bfs(string begin, string target, vector<string> words) {
    auto target_iter = find(words.begin(), words.end(), target);
    if (words.end() == target_iter)
        return;
    queue<pair<string, int>> q;
    q.emplace(begin, 0);
    while(!q.empty()) {
        string now_word = q.front().first;
        int now_num = q.front().second;
        q.pop();
        if (now_word == target) {
            int i = distance(words.begin(), target_iter);
            answer = visited[i];
            return;
        }
        for(int i = 0; i < words.size(); ++i) {
            if (now_word == words[i] || visited[i] != 0)
                continue;
            int count = 0;
            for(int j = 0; j < words[i].size(); ++j) {
                if (now_word[j] == words[i][j])
                    continue;
                count++;
                if (count >= 2)
                    break;
            }
            if (count <= 1) {
                q.emplace(words[i], now_num + 1);
                visited[i] = now_num + 1;
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    bfs(begin, target, words);
    return answer;
}