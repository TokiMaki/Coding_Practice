#include <iostream>

using namespace std;

int factorial(int i) {
	if (i == 1)
		return 1;
	if (i == 0)
		return 1;
	return i * factorial(i - 1);
}

int main() {
	int N;
	cin >> N;
	cout << factorial(N);
}