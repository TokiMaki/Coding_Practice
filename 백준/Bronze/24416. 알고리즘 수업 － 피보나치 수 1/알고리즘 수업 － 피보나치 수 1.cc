#include <iostream>

using namespace std;

int Count[2] = { 0 };

int fib(int n) {
	if (n == 1 || n == 2) {
		Count[0]++;
		return 1;
	}
	else
		return fib(n - 2) + fib(n - 1);
}

int fibonaci(int n) {
	static int f[40];
	f[1 - 1] = 1;
	f[2 - 1] = 1;
	for (int i = 3 - 1; i < n; ++i) {
		Count[1]++;
		f[i] = f[i - 1] + f[i - 2];
	}
	return f[n - 1];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	fib(N);
	fibonaci(N);
	cout << Count[0] << " " << Count[1];
}