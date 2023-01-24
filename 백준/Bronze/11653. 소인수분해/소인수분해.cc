#include <iostream>

int main() {
	int N;
	int i = 2;
	std::cin >> N;
	while (true) {
		if (i > N)
			break;
		if (N % i == 0) {
			std::cout << i << std::endl;
			N /= i;
		}
		else
			++i;
	}
}