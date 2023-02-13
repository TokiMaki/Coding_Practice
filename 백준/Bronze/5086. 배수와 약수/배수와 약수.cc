#include <iostream>

using namespace std;


int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true) {
		int A, B;
		cin >> A >> B;
		if (A == 0 && B == 0)
			break;
		if (A < B && B % A == 0)
			cout << "factor" << "\n";
		else if (A > B && A % B == 0)
			cout << "multiple" << "\n";
		else
			cout << "neither" << "\n";
	}
}