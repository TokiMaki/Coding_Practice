#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;


int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int R;
	cin >> R;
	cout << fixed;
	cout.precision(6);
	cout << R * R * M_PI << "\n";
	cout << R * R * 2 << "\n";
}