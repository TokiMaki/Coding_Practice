#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

unsigned long long answer = 0;

void b_s(unsigned long long start, unsigned long long end, unsigned long long n, vector<int> times) {
    while(start <= end) {
        unsigned long long cnt = 0;
        unsigned long long mid = (start + end) / 2;
        for (unsigned long long i : times) {
            cnt += mid / i;
            if (cnt >= n)
                break;
        }
        if (n <= cnt) {
            if (answer == 0)
                answer = mid;
            else
                answer = min(answer, mid);
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
}

unsigned long long solution(int n, vector<int> times) {
	unsigned long long start = 1;
    unsigned long long end = *max_element(times.begin(), times.end()) * n;
    b_s(start, end, n, times);
    return answer;
}