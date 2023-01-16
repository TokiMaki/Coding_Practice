#include <iostream>
#include <string>

int main() {
	std::string S;
	std::cin >> S;

	int n[] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };

	int result = 0;

	for (char c : S) {
		result += n[c - 'A'];
	}
	std::cout << result;
}