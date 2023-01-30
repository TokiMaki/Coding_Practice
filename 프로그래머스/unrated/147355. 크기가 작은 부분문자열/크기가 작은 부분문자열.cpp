#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long comp = stoll(p);
    int tLength = t.length();
    int pLength = p.length();
    for (int i = 0; i < tLength - (pLength - 1); ++i) {
        long long temp = stoll(t.substr(i, pLength));
        if (temp <= comp)
            answer++;
    }
    return answer;
}