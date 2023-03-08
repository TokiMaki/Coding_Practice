#include <iostream>

using namespace std;

long long Pow(long long a, long long x, long long mod) {
	if (x == 0)
		return 1;
	if (x == 1)
		return a % mod;
	long long half = Pow(a, x / 2, mod);
	if (x % 2 == 1)
		return ((a % mod) * ((half * half) % mod)) % mod;
	else {
		return (half * half) % mod;
	}
}

int main() {
	long long N, K;
	cin >> N >> K;
	long long A = 1, B = 1;
	long long mod = 1000000007;
	for (int i = N; i >= N - K + 1; --i)
		A = A * i % mod;
	for (int i = 1; i <= K; ++i)
		B = B * i % mod;
	B = Pow(B, mod - 2, mod);
	cout << ((A * B) % mod) << '\n';
}