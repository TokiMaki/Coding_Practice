#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, int> um;

    for (string s : phone_book) {
        um.insert({ s, 1 });
    }

    for (string s : phone_book) {
        for (int i = 1; i <= s.length(); ++i) {
            string temp = s.substr(0, i);
            if (um[temp] && temp != s) {
                answer = false;
                break;
            }
        }
    }

    return answer;
}