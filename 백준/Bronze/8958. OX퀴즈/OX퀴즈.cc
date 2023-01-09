#include <iostream>
#include <string>

int main() {
	int N;

	int point = 0;
	int straightpoint = 0;

	std::string s;
	std::cin >> N;

	std::cin.ignore();
	for (int i = 0; i < N; ++i) {
		std::getline(std::cin, s);
		for (int j = 0; j < s.size(); ++j) {
			if (s[j] == 'O') {
				straightpoint++;
				point += straightpoint;
			}
			else
				straightpoint = 0;
		}
		std::cout << point << std::endl;
		s.clear();
		straightpoint = 0;
		point = 0;
	}
}