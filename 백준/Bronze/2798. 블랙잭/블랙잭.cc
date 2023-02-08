#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    // 출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> v;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    int max = INT_MIN;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                int sum = v[i] + v[j] + v[k];
                if (max < sum && sum <= M)
                    max = sum;
            }
        }
    }

    cout << max;
}