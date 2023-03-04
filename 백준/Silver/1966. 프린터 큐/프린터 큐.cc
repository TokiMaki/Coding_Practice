#include <iostream>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		queue<pair<int, int>> q;
		priority_queue<int, vector<int>, less<int>> pq;
		int N, M;
		cin >> N >> M;

		for (int i = 0; i < N; ++i) {
			int tmp;
			cin >> tmp;
			q.push(make_pair(i, tmp));
			pq.push(tmp);
		}

		int cnt = 0;

		while (!q.empty()) {
			if (q.front().second >= pq.top()) {
				cnt++;
				if (q.front().first == M)
					break;
				q.pop();
				pq.pop();
			}
			else {
				q.push(q.front());
				q.pop();
			}
		}
		cout << cnt << '\n';
	}
}