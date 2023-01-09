#include <iostream>

int main() {
	int N;
	std::cin >> N;
	float score[1000];
	int max = 0;
	float sumScore = 0;
    
	std::cout << std::fixed;
	std::cout.precision(2);
    
	for (int i = 0; i < N; ++i) {
		std::cin >> score[i];
		if (max < score[i])
			max = score[i];
	}

	for (int i = 0; i < N; ++i) {
		score[i] = score[i] / max * 100;
		sumScore += score[i];
	}

	std::cout << sumScore / N << std::endl;
}