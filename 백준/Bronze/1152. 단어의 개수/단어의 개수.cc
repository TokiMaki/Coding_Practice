#include <iostream>
#include <string>

int main() {
	std::string S;
	getline(std::cin, S);
	bool connected = true;
	int count = 0;
	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == ' ') {
			connected = true;
		}
		else if (connected == true) {
			count++;
			connected = false;
		}
	}
	std::cout << count;
}