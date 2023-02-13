#include <iostream>
#include <algorithm>

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

	int N;
	cin >> N;
	int firstring;
	cin >> firstring;
	for (int i = 1; i < N; ++i) {
		int tmp;
		cin >> tmp;
		cout<< firstring / gcd(firstring, tmp) << "/" << tmp / gcd(firstring, tmp) << "\n";
	}
}