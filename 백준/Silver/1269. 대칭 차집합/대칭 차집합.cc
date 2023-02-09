#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<int, int> m;
    vector<int> result;

    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        m[tmp]++;
    }

    for (int i = 0; i < M; ++i) {
        int tmp;
        cin >> tmp;
        m[tmp]++;
    }

    for (auto it = m.cbegin(); it != m.cend(); ++it) {
        if (it->second < 2)
            result.push_back(it->first);
    }

    cout << result.size();
}