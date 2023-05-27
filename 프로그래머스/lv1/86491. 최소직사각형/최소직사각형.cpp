#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    
    int answer = 0;
    for(vector<int> &v : sizes) {
        if (v[0] < v[1])
            swap(v[0], v[1]);
    }
    
    int row = 0;
    int columm = 0;
    for(vector<int> v : sizes) {
        row = max(row, v[0]);
        columm = max(columm, v[1]);
    }
    
    answer = row * columm;
    return answer;
}