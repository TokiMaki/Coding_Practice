#include <iostream>

int main() {
	int M, N;
	int min = 10001;
	int sum = 0;
	
	std::cin >> M >> N;
	for (int i = M; i <= N; ++i) {
		if (i == 2) {
			sum += i;
			if (min > i)
				min = i;
			continue;
		}
		for (int j = 2; j <= i - 1; ++j) {
			if (i % j == 0)
				break;
			if (j == i - 1) {
				sum += i;
				if (min > i)
					min = i;
			}
		}
	}
	if (sum == 0)
		std::cout << "-1";
	else
		std::cout << sum << std::endl << min;
}