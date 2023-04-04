#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int Dungeon = 5;
int leftfatigues;
int Sum = 0;
vector<int> Dungeonfatigues;
vector<int> v;
set<vector<int>> s;

void backtracking(int n) {
	if (Sum > leftfatigues - 1)
		return;
	if (Sum == leftfatigues - 1) {
		vector<int> tmp;
		for (int i : v)
			tmp.push_back(i);
		sort(tmp.begin(), tmp.end());
		s.insert(tmp);
	}
	for (int i = 0; i < Dungeon; ++i) {
		if (Sum + Dungeonfatigues[i] <= leftfatigues) {
			Sum += Dungeonfatigues[i];
			v.push_back(Dungeonfatigues[i]);
			backtracking(n + 1);
			Sum -= Dungeonfatigues[i];
			v.pop_back();
		}
	}
}

int main() {
	cout << "��������              �� �� �� Ǯ ��" << endl;
	cout << "������� ��           �� 7  �� 15 ��" << endl;
	cout << "�������ݸ���          �� 6  �� 6  ��" << endl;
	cout << "���ɴϾ� ��           �� 6  �� 9  ��" << endl;
	cout << "���� ��Ʈ             �� 6  �� 12 ��" << endl;
	cout << "������ ���           �� 7  �� 9  ��" << endl;
	cout << "�������� �����     �� 7  �� 11 ��" << endl;
	cout << "������� �︲         �� 8  �� 9  ��" << endl;
	cout << "�����ͳ� �÷��� �����Ҧ� 8  �� 11 ��" << endl;
	while (true) {
		s.clear();
		cout << "���� �Ƿε� : ";
		cin >> leftfatigues;

		Dungeonfatigues.push_back(6);
		Dungeonfatigues.push_back(7);
		Dungeonfatigues.push_back(8);
		Dungeonfatigues.push_back(9);
		Dungeonfatigues.push_back(12);

		vector<int> Count(16);
		backtracking(0);
		if (s.size() <= 0)
			cout << "����� �� ����" << endl;
		else {
			int num = 0;
			for (vector<int> v : s) {
				num++;
				fill(Count.begin(), Count.end(), 0);
				cout << num << "�� �� ";
				for (int i : v) {
					Count[i]++;
				}
				for (int i = 1; i <= 15; ++i) {
					if (Count[i] > 0)
						cout << i << " : " << Count[i] << "ȸ" << " �� ";
				}
				cout << endl;
			}
		}
	}
}