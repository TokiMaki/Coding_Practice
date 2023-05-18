#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> command : commands) {
        int i = command[0] - 1;
        int j = command[1];
        int k = command[2];
        vector<int> newarray(array.begin() + i, array.begin() + j);
        sort(newarray.begin(), newarray.end());
        answer.push_back(newarray[k - 1]);
    }
    return answer;
}