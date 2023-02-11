#include <iostream>
#include <cmath>

using namespace std;


int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	int x[2], y[2], r[2];

	for (int i = 0; i < T; ++i) {

		cin >> x[0] >> y[0] >> r[0] >> x[1] >> y[1] >> r[1];

		double d = sqrt(((x[1] - x[0]) * (x[1] - x[0])) + ((y[1] - y[0]) * (y[1] - y[0])));
		double cond1 = r[0] > r[1] ? r[0] - r[1] : r[1] - r[0];
		double cond2 = r[0] + r[1];

		if (d == 0 && r[0] == r[1]) {
		cout << "-1" << "\n";
		}
		else if (d == cond1 || d == cond2) {
			cout << "1" << "\n";
		}
		else if (d > cond1 && d < cond2) {
			cout << "2" << "\n";
		}
		else {
			cout << "0" << "\n";
		}
	}
}