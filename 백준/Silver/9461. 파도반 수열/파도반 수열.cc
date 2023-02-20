#include <iostream>

using namespace std;

long long a[101] = { };

long long P(int n) {
	a[0] = 0;
	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	a[4] = 2;
	a[5] = 2;
	for (int i = 6; i <= n; ++i) {
		a[i] = a[i - 1] + a[i - 5];
	}
	return a[n];
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		cout << P(tmp) << "\n";
	}
}