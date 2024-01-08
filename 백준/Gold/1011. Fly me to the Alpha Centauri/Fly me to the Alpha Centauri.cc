#include <iostream>
#include <math.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T, x, y;
	int answer;
	cin >> T;
	for(int i = 0; i < T; ++i)
	{
		answer = 0;
		cin >> x >> y;
		int length = y - x;
		int d = sqrt(length);
		answer = (pow(d, 2) == length) ? (2 * d - 1) : 2 * d;
		if (length > pow(d, 2) + d) answer += 1;
		cout << answer << "\n";
	}
}