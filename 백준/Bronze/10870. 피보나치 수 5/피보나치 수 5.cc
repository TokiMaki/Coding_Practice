#include <iostream>

using namespace std;

int pibonacci(int i) {
	if (i == 0)
		return 0;
	if (i == 1)
		return 1;
	return pibonacci(i - 1) + pibonacci(i - 2);
}

int main() {
	// 출력 최적화
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	cout << pibonacci(N);
}