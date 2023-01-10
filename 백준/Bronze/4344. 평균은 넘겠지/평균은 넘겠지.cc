#include <iostream>

int main() {
	int C;
	int N;
	int score[1000];
	float average = 0;
	int aboveAverage = 0;
	std::cin >> C;
	std::cout << std::fixed;
	std::cout.precision(3);
	for (int i = 0; i < C; ++i) {
		std::cin >> N;
		for (int j = 0; j < N; ++j) {
			std::cin >> score[j];
			average += score[j];
		}
		average /= N;
		for (int j = 0; j < N; ++j) {
			if (score[j] > average)
				aboveAverage++;
		}
		std::cout << (aboveAverage / float(N)) * 100 << "%" << std::endl;
		average = 0;
		aboveAverage = 0;
	}
}