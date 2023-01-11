#include <iostream>

int main() {
	std::string S;

	std::cin >> S;
	for (int i = 0; i < 'z' - 'a' + 1; ++i) {
		int order = -1;
		for (int j = 0; j < S.size(); ++j) {
			if (S[j] == ('a' + i)) {
				order = j;
				break;
			}
		}
		std::cout << order << " ";
	}
}