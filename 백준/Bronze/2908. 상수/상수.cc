#include <iostream>
#include <string>

int main() {
	std::string S[2];
	std::cin >> S[0] >> S[1];

	std::string rS[2];
	int rint[2];
	
	for (int i = 0; i < 2; ++i) {
		for (auto j = S[i].rbegin(); j != S[i].rend(); ++j) {
			rS[i] += *j;
		}
		rint[i] = std::stoi(rS[i]);
	}

	if (rint[0] > rint[1])
		std::cout << rint[0];
	else
		std::cout << rint[1];
}