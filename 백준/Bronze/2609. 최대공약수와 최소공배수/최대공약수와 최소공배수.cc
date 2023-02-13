#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	int GCD = gcd(a, b);
	int LCM;
	if (GCD != 0)
		LCM = (a * b) / GCD;
	else
		LCM = 0;

	cout << GCD << "\n" << LCM;
}