#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
	class Info {
	public:
		int num;
		int age;
		string name;
	};

	//백준 입출력 속도 개선
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<Info> v;

	for (int i = 0; i < N; ++i) {
		Info info;
		cin >> info.age >> info.name;
		info.num = i;
		v.push_back(info);
	}

	sort(v.begin(), v.end(), [&](Info a, Info b) {
		if (a.age == b.age) {
			return a.num < b.num;
		}
		else
			return a.age < b.age;
		});

	for (auto a : v) {
		cout << a.age << " " << a.name << "\n";
	}
}