#include <iostream>

int main() {
	int N;
	int num;
	int count = 0;
	
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> num;
		if (num == 2) {
			count++;
			continue;
		}
		for (int j = 2; j <= num - 1; ++j) {
			if (num % j == 0)
				break;
			if (j == num - 1)
				count++;
		}
	}
	std::cout << count;
}