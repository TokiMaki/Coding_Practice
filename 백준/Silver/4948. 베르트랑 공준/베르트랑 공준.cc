#include <iostream>

using namespace std;

int sieve[123456 * 2 + 1] = { 0, };

int isPrimeNumber(int M, int N) {
	int count = 0;
	sieve[0] = 1;
	sieve[1] = 1;
	for (int i = 2; i * i <= N; ++i) {
		if (sieve[i] == 1) {
			continue;
		}
		for (int j = i * i; j <= N; j += i)
			sieve[j] = 1;
	}
	for (int i = M + 1; i <= N; ++i) {
		if (sieve[i] == 0)
			count++;
	}
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int N;
		std::cin >> N;
		if (N == 0)
			break;
		cout << isPrimeNumber(N, 2 * N) << "\n";
	}
}