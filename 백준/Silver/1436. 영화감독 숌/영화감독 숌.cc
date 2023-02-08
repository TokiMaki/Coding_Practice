#include <iostream>

using namespace std;

int main() {
    // 출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int num = 666;
    int count = 0;

    while (true) {
        int temp = num;
        while (temp > 0) {
            if (temp % 1000 == 666) {
                count++;
                break;
            }
            else
                temp /= 10;
        }
        if (count < N)
            num++;
        else
            break;
    }
     
    cout << num;
}