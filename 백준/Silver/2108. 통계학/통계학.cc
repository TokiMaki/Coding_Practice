#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	vector<int> v;

	vector<int> modevector;

	int average = 0;
	int counting[8001] = {0, };
	int max = INT_MIN;
	int min = INT_MAX;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		//산술평균
		average += temp;
		counting[temp + 4000]++;
		//범위를 위한
		if (max < temp)
			max = temp;
		if (min > temp)
			min = temp;
	}

	//산술평균
	average = round(average / float(N));
	cout << average << "\n";

	// 중앙값
	sort(v.begin(), v.end(), less<>());
	cout << v[(N - 1) / 2] << "\n";

	//최빈값
	int modemax = 0;
	for (int i = -4000; i <= 4000; ++i) {
		if (counting[i + 4000] > modemax) {
			modemax = counting[i + 4000];
			modevector.clear();
			modevector.push_back(i);
		}
		else if(counting[i + 4000] == modemax) {
			modevector.push_back(i);
		}
	}

	if (modevector.size() >= 2) {
		cout << modevector[1] << "\n";
	}
	else
		cout << modevector[0] << "\n";

	//범위
	cout << max - min << "\n";
}