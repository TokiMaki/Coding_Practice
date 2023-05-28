#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> v(n + 1);
    fill_n(v.begin(), n + 1, 1);
    
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
    for(int i : lost)
        v[i]--;
    for(int i : reserve) {
        v[i]++;
    }
    
    for(int i : reserve) {
        if (v[i] >= 2){
            if (i - 1 >= 1) {
                if (v[i - 1] == false) {
                    v[i - 1] = true;
                    continue;
                }
            }
            if (i + 1 <= n) {
                if (v[i + 1] == false) {
                    v[i + 1] = true;
                    continue;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; ++i) {
        if (v[i] >= 1)
            answer++;
    }
    
    return answer;
}