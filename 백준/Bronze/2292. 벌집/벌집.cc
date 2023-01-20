#include <iostream>

int main() {
	int N;

	int count = 0;

	std::cin >> N;

	while (N > 0) {
		if (count == 0)
			N -= 1;
		else
			N -= (6 * count);
		count++;
	}
	std::cout << count;
}