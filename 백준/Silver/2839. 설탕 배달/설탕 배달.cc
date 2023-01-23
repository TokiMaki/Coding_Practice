#include <iostream>

int main() {
	int N;
	std::cin >> N;
	for (int i = N / 5; i >= 0; --i) {
		if ((N - i * 5) % 3 == 0) {
			std::cout << i + (N - i * 5) / 3;
			return 0;
		}
	}
	std::cout << "-1";
}