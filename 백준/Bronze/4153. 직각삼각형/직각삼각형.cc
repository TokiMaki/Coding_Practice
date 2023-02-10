#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool Pythagoras(int x, int y, int z) {
	if ((x * x + y * y) == (z * z)) {
		return true;
	}
	else
		return false;
}

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int v[3];
		cin >> v[0] >> v[1] >> v[2];

		if (v[0] == 0 && v[1] == 0 && v[2] == 0)
			break;

		int maximum = 0;
		int maxindex = -1;
		for (int i = 0; i < 3; ++i) {
			maximum = max(maximum, v[i]);
			if (maximum == v[i])
				maxindex = i;
		}
		swap(v[maxindex], v[2]);
		if (true == Pythagoras(v[0], v[1], v[2]))
			cout << "right" << "\n";
		else
			cout << "wrong" << "\n";
	}
}