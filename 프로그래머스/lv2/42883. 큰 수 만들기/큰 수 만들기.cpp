#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for (int i = 0; i < k; ++i) {
        bool deletecheck = false;
        for (int j = 0; j < number.size() - 1; ++j) {
            if (number[j] < number[j + 1]) {
                deletecheck = true;
                number.erase(number.begin() + j);
                break;
            }
        }
        if (deletecheck == false) {
            number.erase(number.end() - 1);
        }
    }
    answer = number;
    return answer;
}