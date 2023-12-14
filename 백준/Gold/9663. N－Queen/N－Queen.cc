#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int chess[16];
int N;
int answer;

bool check(int x)
{
	for(int i = 0; i < x; ++i)
	{
		if (chess[i] == chess[x] || x - i == abs(chess[x] - chess[i]))
			return false;
	}
	return true;
}

void nQueen(int x)
{
	if (x >= N) {
		answer += 1;
		return;
	}
	for(int i = 0; i < N; ++i)
	{
		chess[x] = i;
		if (check(x) != false)
			nQueen(x + 1);
	}
}

int main() {
	cin >> N;
	answer = 0;
	nQueen(0);
	cout << answer;
}