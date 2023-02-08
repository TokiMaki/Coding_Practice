#include <iostream>
#include <vector>

using namespace std;

int main() {
    class Info {
    public:
        int x;
        int y;
        int order = 1;
    };
    // 출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    vector<Info> v;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        Info info;
        cin >> info.x >> info.y;
        v.push_back(info);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int compare = 0;

            if (v[i].x > v[j].x && v[i].y > v[j].y)
                compare -= 1;
            else if (v[i].x < v[j].x && v[i].y < v[j].y)
                compare += 1;

            if (compare < 0)
                v[j].order += 1;
            else if (compare > 0)
                v[i].order += 1;
        }
    }

    for (Info info : v) {
        cout << info.order << " ";
    }
}