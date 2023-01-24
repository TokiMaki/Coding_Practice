#include <iostream>

using namespace std;

int sieve[1000000 + 1] = { 0, };

void isPrimeNumber(int M, int N) {
	sieve[0] = 1;
	sieve[1] = 1;
	for (int i = 2; i * i <= N; ++i) {
		if (sieve[i] == 1) {
			continue;
		}
		for (int j = i * i; j <= N; j += i)
			sieve[j] = 1;
	}
	for (int i = M; i <= N; ++i) {
		if (sieve[i] == 0)
			cout << i << "\n";
	}
}

int main() {

	int M, N;
	std::cin >> M >> N;

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	isPrimeNumber(M, N);
}