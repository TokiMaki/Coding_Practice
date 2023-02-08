#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    // 출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    string s = "0";
    while (true) {
        int tmp = stoi(s);
        for (char c : s) {
            int num = c - '0';
            tmp += num;
        }
        if (tmp == N)
            break;
        else if (stoi(s) > N) {
            s = "0";
            break;
        }
        else
            s = to_string(stoi(s) + 1);
    }
    cout << s;
}