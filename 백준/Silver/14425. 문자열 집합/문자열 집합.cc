#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    int count = 0;
    cin >> N >> M;

    vector<string> S;
    vector<string> MS;

    for (int i = 0; i < N; ++i) {
        string tmp;
        cin >> tmp;
        S.push_back(tmp);
    }

    sort(S.begin(), S.end());

    for (int i = 0; i < M; ++i) {
        string tmp;
        cin >> tmp;
        MS.push_back(tmp);
    }

    for (string s : MS) {
        if (true == binary_search(S.cbegin(), S.cend(), s))
            count++;
    }
    cout << count;
}