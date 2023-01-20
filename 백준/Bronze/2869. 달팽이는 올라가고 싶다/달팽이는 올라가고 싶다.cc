#include <iostream>
#include <cmath>

int main() {
	int A, B, V;
	int rise = 0;
	int day = 0;

	std::cin >> A >> B >> V;

	V -= A;
	rise = A - B;
	day = V / rise;
	if (V % rise != 0)
		day += 1;

	std::cout << day + 1;
}