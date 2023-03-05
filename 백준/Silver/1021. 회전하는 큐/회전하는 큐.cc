#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;

	deque<int> d;

	for (int i = 1; i <= N; ++i) {
		d.push_back(i);
	}

	int answer = 0;

	for (int i = 0; i < M; ++i) {
		int num;
		cin >> num;

		int left;
		int right;

		for (int i = 0; i < d.size(); ++i) {
			if (d[i] == num) {
				left = i;
				right = d.size() - i;
				break;
			}
		}
		if (left <= right) {
			while (true) {
				if (d.front() == num) {
					d.pop_front();
					break;
				}
				d.push_back(d.front());
				d.pop_front();
				answer++;
			}
		}
		else {
			while (true) {
				if (d.front() == num) {
					d.pop_front();
					break;
				}
				d.push_front(d.back());
				d.pop_back();
				answer++;
			}
		}

	}

	cout << answer;
}