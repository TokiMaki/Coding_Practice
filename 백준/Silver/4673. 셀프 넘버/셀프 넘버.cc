#include <iostream>

int selfnumber(int n) {
	int number = n;
	int sum = n;
	while (number != 0) {
		sum = sum + (number % 10);
		number /= 10;
	}
	return sum;
}

int main() {
	bool check[10001];
	std::fill_n(check, 10001, false);
	int i = 1;
	for(int i = 1; i < 10001; ++i){
		int n = selfnumber(i);
		if (n < 10001)
			check[n] = true;
	}
	for (int i = 1; i < 10001; ++i) {
		if (!check[i])
			std::cout << i << std::endl;
	}
}