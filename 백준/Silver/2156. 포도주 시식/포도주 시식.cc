#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> grape(N);			
	vector<int> maxgrape(N);		// 포도주가 N잔있을때 가장 많이 먹을 수 있는 양

	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		grape[i] = tmp;
	}

	maxgrape[0] = grape[0];
	maxgrape[1] = grape[0] + grape[1];
	maxgrape[2] = max(maxgrape[1],max(grape[0] + grape[2], grape[1] + grape[2]));
	for (int i = 3; i < N; ++i) {
		maxgrape[i] = max(maxgrape[i - 1], max(maxgrape[i - 2] + grape[i], maxgrape[i - 3] + grape[i - 1] + grape[i]));
	}

	cout << maxgrape[N - 1];
}