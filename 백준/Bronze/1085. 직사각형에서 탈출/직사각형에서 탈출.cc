#include <iostream>
#include <climits>

using namespace std;

int main() {
	// 출력 최적화
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, y;
	int w, h;
	cin >> x >> y;
	cin >> w >> h;
	int min = INT_MAX;

	if (min > x)
		min = x;
	if (min > y)
		min = y;
	if (min > w - x)
		min = w - x;
	if (min > h - y)
		min = h - y;

	cout << min;
}