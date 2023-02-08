#include <iostream>
#include <vector>
#include <climits>

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

    int N, M;
    char chess[50][50] = {NULL, };
    
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> chess[i][j];
        }
    }

    int min = INT_MAX;

    for (int i = 0; i < N - 7; ++i) {
        for (int j = 0; j < M - 7; ++j) {
            for (int k = 0; k < 2; ++k) {
                int count = 0;
                char beforecolor = (k == 0) ? 'B' : 'W';
                for (int l = i; l < i + 8; ++l) {
                    if (l != 0) {
                        beforecolor = (beforecolor == 'W') ? 'B' : 'W';
                    }
                    for (int m = j; m < j + 8; ++m) {
                        if (beforecolor != chess[l][m]) {
                            beforecolor = chess[l][m];
                        }
                        else {
                            beforecolor = (beforecolor == 'W') ? 'B' : 'W';
                            count++;
                        }
                        if (count > min)
                            break;
                    }
                    if (count > min)
                        break;
                }
                if (min > count)
                    min = count;
            }
        }
    }
    cout << min;
}