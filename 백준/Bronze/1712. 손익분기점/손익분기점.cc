#include <iostream>

int main() {
	int A, B, C;

	std::cin >> A >> B >> C;
	
	long long count = 0;
	long long profit = C - B;
	long long total = A;
	long long breakevenpoint = 0;
	
	if (B > C || B == C) {
		count = -1;
		std::cout << count;
		return 0;
	}
	count = A / profit + 1;

	std::cout << count;
}