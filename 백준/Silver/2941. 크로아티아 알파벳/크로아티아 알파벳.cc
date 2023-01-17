#include <iostream>
#include <string>

int main() {
	std::string S;

	std::string CroatiaAlphabet[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };

	int index = 0;
	int result = 0;
	int i = 0;

	std::cin >> S;

	while (i < sizeof(CroatiaAlphabet) / sizeof(std::string)) {
		int begin = S.find(CroatiaAlphabet[i]);
		int length;
		if (begin != std::string::npos) {
			length = CroatiaAlphabet[i].length();
			S.replace(begin, length, "0");
		}
		else {
			std::string copyS = S;
			++i;
		}
	}
	result += S.length();
	std::cout << result;
}