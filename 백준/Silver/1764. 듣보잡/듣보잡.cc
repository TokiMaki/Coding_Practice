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
    cin >> N >> M;

    vector<string> Nv;

    vector<string> result;

    for (int i = 0; i < N; ++i) {
        string tmp;
        cin >> tmp;
        Nv.push_back(tmp);
    }

    sort(Nv.begin(), Nv.end());

    for (int i = 0; i < M; ++i) {
        string tmp;
        cin >> tmp;
        if (binary_search(Nv.cbegin(), Nv.cend(), tmp))
            result.push_back(tmp);
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";

    for (string s : result)
        cout << s << "\n";
}