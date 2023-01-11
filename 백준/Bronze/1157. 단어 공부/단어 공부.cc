#include <iostream>

int main() {
	std::string S;
	int alphaNum[26];
	std::fill_n(alphaNum, 26, 0);
	std::cin >> S;
	for (auto c : S) {
		if (c >= 'a' && c <= 'z')
			alphaNum[c - 'a']++;
		else if (c >= 'A' && c <= 'Z')
			alphaNum[c - 'A']++;
	}
	int max = 0;
	char maxalpha;
	for (int i = 0; i < 26; ++i) {
		if (max < alphaNum[i]) {
			max = alphaNum[i];
			maxalpha = 'A' + i;
		}
		else if (max == alphaNum[i])
			maxalpha = '?';
	}
	std::cout << maxalpha << std::endl;
}