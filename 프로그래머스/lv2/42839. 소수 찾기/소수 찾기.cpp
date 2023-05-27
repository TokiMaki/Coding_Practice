#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

set<int> s;
string number = "";
bool visited[7];

void dfs(string numbers, int num) {
    if (numbers.length() <= num) {
        s.insert(stoi(number));
        return;
    }
    else {
        if (num > 0)
            s.insert(stoi(number));
        for (int i = 0; i < numbers.length(); ++i) {
            if (visited[i] == false) {
                number += numbers[i];
                visited[i] = true;
                dfs(numbers, num + 1);
                visited[i] = false;
                string temp = "";
                for (int i = 0; i < num; ++i) {
                    temp += number[i];
                }
                number = temp;
            }
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    dfs(numbers, 0);
    for (int i : s) {
        bool check = true;
        if (i == 0 || i == 1)
            check = false;
        else {
            for (int j = 2; j <= sqrt(i); ++j) {
                if (i % j == 0) {
                    check = false;
                    break;
                }
            }
        }
        if (check == true)
            answer++;
    }
    
    return answer;
}