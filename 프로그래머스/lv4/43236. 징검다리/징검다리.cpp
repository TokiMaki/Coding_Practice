#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int answer = 1;
void b_s(int distance, vector<int> rocks, int n) {
    int low = 1;
    int high = distance;
    while (low <= high) {
        int mid = (low + high) / 2;
        int cnt = 0;
        int prev = 0;
        for(int i = 0; i < rocks.size(); ++i)
        {
            if (rocks[i] - prev < mid)
                cnt++;
            else
                prev = rocks[i];
        }
        if (distance - prev < mid)
            cnt++;
        if (cnt > n) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    answer = low - 1;
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    b_s(distance, rocks, n);
    return answer;
}
