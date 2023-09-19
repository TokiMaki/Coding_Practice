#include <iostream>
#include <cmath>

using namespace std;

int N, r, c;
bool finish = false;
int answer = 0;

void dc(int x, int y, int size)
{
	if ((x == c && y == r) || finish == true)
	{
		finish = true;
		return;
	}
	else if (c < x + size && c >= x && r < y + size && r >= y) {
		dc(x, y, size / 2);
		dc(x + size / 2, y, size / 2);
		dc(x, y + size / 2, size / 2);
		dc(x + size / 2, y + size / 2, size / 2);
	}
	else
		answer += size * size;
}

int main()
{
	cin >> N >> r >> c;
	N = pow(2, N);
	dc(0, 0, N);
	cout << answer;
}