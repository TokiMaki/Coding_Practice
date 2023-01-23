#include <iostream>

int getNum(int k, int n) {
	if (n == 1)
		return 1;
	if (k == 0)
		return n;
	return (getNum(k - 1, n) + getNum(k, n - 1));
}

int main() {
	int T;
	std::cin >> T;
	int k, n;

	for (int i = 0; i < T; ++i) {
		std::cin >> k >> n;
		std::cout << getNum(k, n) << std::endl;
	}
}