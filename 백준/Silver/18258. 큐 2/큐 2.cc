#include <iostream>

using namespace std;

class List {
public:
	int num;
	List* next;
};

class Queue {
public:
	List* first;
	List* Q;
	List* last;
	int cnt;
	Queue() {
		Q = new List;
		Q->num = -1;
		Q->next = nullptr;
		first = Q;
		last = Q;
		cnt = 0;
	}
	void push(int x) {
		List* tmp = new List;
		tmp->num = x;
		tmp->next = nullptr;
		last->next = tmp;
		last = tmp;
		cnt++;
	}
	int pop() {
		if (first == last)
			return -1;
		else {
			int returnValue = first->next->num;
			List* tmp = first->next;
			if (first->next == last)
				last = first;
			first->next = first->next->next;
			delete(tmp);
			cnt--;
			return returnValue;
		}
	}
	int size() {
		return cnt;
	}
	bool empty() {
		return first == last;
	}
	int front() {
		if (!empty())
			return first->next->num;
		else
			return -1;
	}
	int back() {
		if (!empty())
			return last->num;
		else
			return -1;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	Queue q;
	for (int i = 0; i < N; ++i) {
		string command;
		cin >> command;
		if (command == "push") {
			int x;
			cin >> x;
			q.push(x);
		}
		if (command == "pop") {
			cout << q.pop() << '\n';
		}
		if (command == "size") {
			cout << q.size() << '\n';
		}
		if (command == "empty") {
			cout << q.empty() << '\n';
		}
		if (command == "front") {
			cout << q.front() << '\n';
		}
		if (command == "back") {
			cout << q.back() << '\n';
		}
	}
}