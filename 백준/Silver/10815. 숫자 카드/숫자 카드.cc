#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;

    vector<int> Nv;
    vector<int> Mv;

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
        Mv.push_back(tmp);
    }

    for (int i : Mv) {
        if (binary_search(Nv.cbegin(), Nv.cend(), i))
            cout << "1" << " ";
        else
            cout << "0" << " ";
    }

}