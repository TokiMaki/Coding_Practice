#include <iostream>
#include <vector>
using namespace std;

int K = 0;
vector <pair<int, int>> process;

void hanoi(int N, int start, int to, int via)
{
    if (N == 1) {
        K++;
        process.push_back(make_pair(start, to));
    }
    else {
        hanoi(N - 1, start, via, to);
        K++;
        process.push_back(make_pair(start, to));
        hanoi(N - 1, via, to, start);
    }
}
int main() {
    // 출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    hanoi(N, 1, 3, 2);
    cout << K << "\n";
    for (auto p : process)
        cout << p.first << " " << p.second << "\n";
}