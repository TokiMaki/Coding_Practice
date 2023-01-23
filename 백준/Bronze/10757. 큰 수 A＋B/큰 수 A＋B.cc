#include <iostream>
#include <algorithm>
#include <string>

int main() {
	std::string A;
	std::string B;
	std::string result;
	int len;
	int roundup = 0;

	std::cin >> A >> B;

	len = (A.length() > B.length()) ? A.length() : B.length();
	std::reverse(A.begin(), A.end());
	std::reverse(B.begin(), B.end());

	for (int i = 0; i < len; ++i) {
		int Ai = (i < A.length()) ? (A[i] - '0') : 0;
		int Bi = (i < B.length()) ? (B[i] - '0') : 0;
		int sum = Ai + Bi + roundup;
		if (sum > 9)
			roundup = 1;
		else
			roundup = 0;
		result = char((sum % 10) + '0') + result;
	}

	if (roundup == 1)
		result = char(1 + '0') + result;
	std::cout << result;
}