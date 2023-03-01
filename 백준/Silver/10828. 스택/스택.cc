#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class List {
public:
	int num;
	List* next;
};

class Stack {
public:
	List* first;
	List* list;
	List* last;
	Stack() {
		list = new List();
		list->num = 0;
		list->next = nullptr;
		first = list;
		last = list;
	}
	void Push(int num) {
		List* tmp = new List();
		tmp->num = num;
		last->next = tmp;
		last = tmp;
	}
	int Pop() {
		if (empty() == 1) {
			return -1;
		}
		else {
			int returnValue = last->num;
			List* tmp = first;
			while (tmp->next != last) {
				tmp = tmp->next;
			}
			delete(last);
			tmp->next = nullptr;
			last = tmp;
			return returnValue;
		}
	}
	int Size() {
		if (empty() == 1)
			return 0;
		int cnt = 0;
		List* tmp = first;
		while (tmp != last) {
			tmp = tmp->next;
			cnt++;
		}
		return cnt;
	}
	int empty() {
		if (first == last) {
			return 1;
		}
		else
			return 0;
	}
	int top() {
		if (empty() == 1)
			return -1;
		int returnValue = last->num;
		return returnValue;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Stack S;
	int N;
	cin >> N;
	string command;
	stringstream stream;
	for (int i = 0; i < N; ++i) {
		cin >> command;
		if (command == "push") {
			int num;
			cin >> num;
			S.Push(num);
		}
		else if (command == "pop") {
			cout << S.Pop() << "\n";
		}
		else if (command == "size") {
			cout << S.Size() << "\n";
		}
		else if (command == "empty") {
			cout << S.empty() << "\n";
		}
		else if (command == "top") {
			cout << S.top() << "\n";
		}
	}
}