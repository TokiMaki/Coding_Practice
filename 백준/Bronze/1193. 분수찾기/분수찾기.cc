#include <iostream>

int main() {
	int X;
	int count = 1;
	std::cin >> X;
	while (X > count) {
		X -= count;
		count++;
	}

	if (count % 2 == 1)
		std::cout << count + 1 - X << "/" << X;
	else
		std::cout << X << "/" << count + 1 - X;
}