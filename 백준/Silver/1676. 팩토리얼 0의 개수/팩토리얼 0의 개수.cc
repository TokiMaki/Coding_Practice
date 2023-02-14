#include <iostream>

using namespace std;

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int result = 0;

	for (int i = 5; i <= N; i *= 5)
		result += N / i;
	cout << result;
}