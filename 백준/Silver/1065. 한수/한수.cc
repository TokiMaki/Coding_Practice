#include <iostream>

int hannum(int n) {
	int count = 0;
	for (int i = 1; i <= n; ++i) {
		int num = i;
		int comp = -1;
		int distance = 10;
		bool succ = true;
		while (num != 0) {
			if (comp == -1) {
				comp = num % 10;
				num /= 10;
			}
			else if (distance == 10) {
				distance = comp - (num % 10);
				comp = num % 10;
				num /= 10;
			}
			else if (comp - (num % 10) == distance) {
				comp = num % 10;
				num /= 10;
			}
			else {
				succ = false;
				break;
			}
		}
		if (true == succ)
			count++;
	}
	return count;
}

int main() {
	int N;
	std::cin >> N;
	std::cout << hannum(N) << std::endl;
}