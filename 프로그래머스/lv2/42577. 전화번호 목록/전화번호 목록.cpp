#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, vector<int>> um;

    for (int i = 0; i < phone_book.size(); ++i) {
        for (int j = 1; j <= phone_book[i].length(); ++j) {
            string nexts;
            nexts.assign(phone_book[i], 0, j);
            auto findnext = um.find(nexts);
            if (findnext == um.end()) {
                vector<int> v;
                v.push_back(i);
                um.insert({ nexts, v });
            }
            else {
                findnext->second.push_back(i);
            }
        }
    }

    for (int i = 0; i < phone_book.size(); ++i) {
        auto findnext = um.find(phone_book[i]);
        if (findnext != um.end()) {
            if (find_if(findnext->second.begin(), findnext->second.end(), [&i](int ii){return i != ii;}) 
                != findnext->second.end()) {
                answer = false;
                break;
            }
        }
    }

    return answer;
}