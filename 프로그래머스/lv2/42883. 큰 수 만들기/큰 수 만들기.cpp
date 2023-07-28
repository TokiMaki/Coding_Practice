#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(int i = 0; i < k; ++i) {
        bool check = false;
        for(int j = 0; j < number.size() - 1; ++j) {
            if (number[j] < number[j + 1]) {
                number.erase(number.begin() + j);
                check = true;
                break;
            }
        }
        if (check == false)
            number.erase(number.end() - 1);
    }
    answer = number;
    return answer;
}