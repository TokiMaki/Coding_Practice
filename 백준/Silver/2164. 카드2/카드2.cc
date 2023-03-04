#include <iostream>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	queue<int> q;
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; ++i) {
		q.push(i);
	}

	if (q.size() <= 1) {
		cout << q.front();
		return 0;
	}

	while (true) {
		q.pop();
		if (q.size() <= 1)
			break;
		int tmp = q.front();
		q.pop();
		q.push(tmp);
	}

	cout << q.front();
}