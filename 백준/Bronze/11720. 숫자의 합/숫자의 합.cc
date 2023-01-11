#include <iostream>

int main() {
	int N;
	char num[100];
	int sum = 0;
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> num[i];
		sum += int(num[i]) - '0';
	}
	std::cout << sum << std::endl;
}