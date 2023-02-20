#include <iostream>
#include <cmath>

using namespace std;

long long binary(int n) {
	static long long a[1000001] = { };
	
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;

	for (int i = 3; i <= n; ++i) {
		a[i] = (a[i - 1] + a[i - 2]) % 15746;
	}
	return a[n];
}

int main() {
	int N;
	cin >> N;
	cout << binary(N);
}