#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    // 출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    map<int, int> Nm;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        if (Nm.find(tmp) != Nm.end())
            Nm[tmp] += 1;
        else
            Nm[tmp] = 1;
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int tmp;
        cin >> tmp;
        if (Nm.find(tmp) != Nm.end())
            cout << Nm[tmp] << " ";
        else
            cout << "0" << " ";
    }
}