#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

void runCommend(string commend)
{
	if (commend == "push")
	{
		int pushNum;
		cin >> pushNum;
		q.push(pushNum);
	}
	else if (commend == "pop")
	{
		if (q.empty())
			cout << "-1" << endl;
		else
		{
			cout << q.front() << endl;
			q.pop();
		}
	}
	else if (commend == "size")
	{
		cout << q.size() << endl;
	}
	else if (commend == "empty")
	{
		if (q.empty())
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
	else if (commend == "front")
	{
		if (q.empty())
			cout << "-1" << endl;
		else
			cout << q.front() << endl;
	}
	else if (commend == "back")
	{
		if (q.empty())
			cout << "-1" << endl;
		else
			cout << q.back() << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	string commend;
	for (int i = 0; i < N; ++i) {
		cin >> commend;
		runCommend(commend);
	}
}