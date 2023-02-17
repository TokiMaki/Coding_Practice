#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> v;
int Operator[4] = { 0 };
int Max = -1000000000;
int Min = 1000000000;

void d(int result, int x) {
	if (x >= v.size()) {
		if (Max < result)
			Max = result;
		if (Min > result)
			Min = result;
	}

	for (int i = 0; i < 4; ++i) {
		if (Operator[i] > 0) {
			Operator[i]--;
			if (i == 0) {
				d(result + v[x], x + 1);
			}
			else if (i == 1) {
				d(result - v[x], x + 1);
			}
			else if (i == 2) {
				d(result * v[x], x + 1);
			}
			else if (i == 3) {
				d(result / v[x], x + 1);
			}
			Operator[i]++;
		}
	}
}

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio;
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	for (int i = 0; i < 4; ++i)
		cin >> Operator[i];
	d(v[0], 1);
	cout << Max << "\n" << Min;
}