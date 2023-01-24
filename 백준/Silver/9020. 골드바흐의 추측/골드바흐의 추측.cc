#include <iostream>
#include <cstdlib>

using namespace std;

int sieve[10000 + 1] = { 0, };

void goldBach(int N) {
	int A, B = 0;
	int diff = 2147483647;
	sieve[0] = 1;
	sieve[1] = 1;
	for (int i = 2; i * i <= N; ++i) {
		if (sieve[i] == 1) {
			continue;
		}
		for (int j = i * i; j <= N; j += i)
			sieve[j] = 1;
	}
	for (int i = 2; i <= N / 2; ++i) {
		if (sieve[i] == 0 && sieve[N - i] == 0)
			if (diff > abs(i - (N - i))) {
				diff = abs(i - (N - i));
				A = i;
				B = N - i;
			}
	}
	if (A != 0 && B != 0)
		cout << A << " " << B << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;

	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N;
		std::cin >> N;
		goldBach(N);
	}
}