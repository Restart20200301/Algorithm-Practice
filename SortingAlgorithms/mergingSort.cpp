#include <iostream>
using namespace std;

template<typename Type>
void merge(Type* data, Type* copyData, int low, int high) {
	if (low >= high) return;
	int mid = low + ((high - low) >> 1);
	merge(data, copyData, low, mid);
	merge(data, copyData, mid + 1, high);
	int left = low;
	int right = mid + 1;
	int pos = 0;
	while (left <= mid && right <= high) {
		if (data[left] < data[right]) {
			copyData[pos++] = data[left++];
		}
		else {
			copyData[pos++] = data[right++];
		}
	}
	while (left <= mid) copyData[pos++] = data[left++];
	while (right <= high) copyData[pos++] = data[right++];
	for (int i = low, pos = 0; i <= high; i++)
		data[i] = copyData[pos++];
}

template<typename Type>
void mergingSort(Type* data, int n) {
	Type* copyData = new Type[n];
	merge(data, copyData, 0, n - 1);
	delete[] copyData;
}

int main() {
	int data[] = { 12, 1, 25, 75, 12, 45, 1, 65, 45, 26, 12, 45, 14, 12, 14 };
	mergingSort(data, 15);
	for (int i = 0; i < 15; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}