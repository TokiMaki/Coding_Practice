#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;

int n = 10;
int OriginArray[10] = { 7, 5, 9, 0, 3, 1, 6, 2, 4, 8 };
int Array[10];

// 선택정렬 시간복잡도 N 제곱
void SelectSort() {
	for (int i = 0; i < n; ++i)
		Array[i] = OriginArray[i];

	for (int i = 0; i < n; ++i) {
		int MinNum = -1;
		int MinIndex = -1;
		for (int j = i; j < n; ++j) {
			if (MinIndex == -1 || MinNum > Array[j]) {
				MinIndex = j;
				MinNum = Array[j];
			}
		}
		int tmp = Array[i];
		Array[i] = Array[MinIndex];
		Array[MinIndex] = tmp;
	}

	for (int i = 0; i < n; ++i)
		cout << Array[i] << " ";
	cout << endl;
}

// 삽입정렬 시간복잡도 N 제곱
void InsertSort() {
	for (int i = 0; i < n; ++i)
		Array[i] = OriginArray[i];

	for (int i = 1; i < n; ++i) {
		for (int j = i; j > 0; --j) {
			if (Array[j] < Array[j - 1])
				swap(Array[j], Array[j - 1]);
			else
				break;
		}
	}

	for (int i = 0; i < n; ++i)
		cout << Array[i] << " ";
	cout << endl;
}

void QuickSort(int start, int end) {
	if (start >= end)
		return;

	int mid = (start + end) / 2;

	swap(Array[mid], Array[start]);
	int pivot = start;
	int left = start + 1;
	int right = end;

	while (left <= right) {
		while (left <= end && Array[left] <= Array[pivot])
			left++;
		while (right > start && Array[right] > Array[pivot])
			right--;
		if (left > right)
			swap(Array[pivot], Array[right]);
		else
			swap(Array[left], Array[right]);
	}
	QuickSort(start, right - 1);
	QuickSort(right + 1, end);
}

void CountingSort() {
	for (int i = 0; i < n; ++i)
		Array[i] = OriginArray[i];

	int CountArray[10] = { 0, };
	for (int i = 0; i < n; ++i) {
		CountArray[Array[i]]++;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < CountArray[i]; ++j) {
			cout << i << " ";
		}
	cout << endl;
}

int main() {
	auto startTime = std::chrono::system_clock::now();

	SelectSort();

	auto endTime = std::chrono::system_clock::now();
	auto sec = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
	cout << sec.count() << "ns" << endl;

	startTime = std::chrono::system_clock::now();

	InsertSort();

	endTime = std::chrono::system_clock::now();
	sec = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
	cout << sec.count() << "ns" << endl;

	startTime = std::chrono::system_clock::now();

	for (int i = 0; i < n; ++i)
		Array[i] = OriginArray[i];

	QuickSort(0, 9);

	for (int i = 0; i < n; ++i)
		cout << Array[i] << " ";
	cout << endl;

	endTime = std::chrono::system_clock::now();
	sec = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
	cout << sec.count() << "ns" << endl;

	startTime = std::chrono::system_clock::now();

	CountingSort();

	endTime = std::chrono::system_clock::now();
	sec = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
	cout << sec.count() << "ns" << endl;

}