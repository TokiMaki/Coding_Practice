#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    vector<int> Nv;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        Nv.push_back(tmp);
    }

    sort(Nv.begin(), Nv.end());

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int tmp;
        cin >> tmp;
        auto result = upper_bound(Nv.begin(), Nv.end(), tmp) - lower_bound(Nv.begin(), Nv.end(), tmp);
        cout << result << " ";
    }
}