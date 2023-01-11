#include <iostream>

int main() {
	std::string S;
	int T, R;

	std::cin >> T;
	for (int i = 0; i < T; ++i) {
		std::cin >> R >> S;
		for (auto c : S) {
			for (int i = 0; i < R; ++i)
				std::cout << c;
		}
		std::cout << std::endl;
	}
}