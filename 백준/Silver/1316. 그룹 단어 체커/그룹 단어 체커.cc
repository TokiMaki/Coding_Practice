#include <iostream>
#include <string>

int main() {
	int N;
	std::cin >> N;
	std::string S[100];

	bool sequenceAlphabet[26];

	int count = 0;

	for (int i = 0; i < N; ++i) {
		std::cin >> S[i];
		bool check = true;
		char beforeChar = NULL;
		std::fill_n(sequenceAlphabet, 26, false);
		for (char c : S[i]) {
			if (beforeChar == NULL || beforeChar != c) {
				if (sequenceAlphabet[c - 'a'] == false) {
					sequenceAlphabet[c - 'a'] = true;
					beforeChar = c;
				}
				else {
					check = false;
					break;
				}
			}
		}
		if (check == true)
			count++;
	}

	std::cout << count;
}