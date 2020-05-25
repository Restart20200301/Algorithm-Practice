// 寻找数组中的最大值和最小值

#include <iostream>
#include <utility>
using namespace std;

pair<int, int> findMaxAndMin(int arr[], int n) {
	int max, min;
	max = min = arr[0];
	for (int i = 1; i < n; i++) {
		if (max < arr[i])
			max = arr[i];
		else if (min > arr[i])
			min = arr[i];
	}
	return make_pair(max, min);
}

// 分组比较
pair<int, int> findMaxAndMin2(int arr[], int n) {
	for (int i = 0; i < (n >> 1); i++) {
		if (arr[i] < arr[2 * i]) swap(arr[n - i - 1], arr[i]);
	}
	int min = arr[0];
	for (int i = 1; i <= (n >> 1); i++) {
		if (min > arr[i]) min = arr[i];
	}

	int max = arr[n >> 1];
	for (int i = (n >> 1); i < n; i++) {
		if (max < arr[i]) max = arr[i];
	}

	return make_pair(max, min);
}

// 不改变原始数组的分组比较
pair<int, int> findMaxAndMin3(int arr[], int n) {
	int min, max;
	min = max = arr[0];
	for (int i = 0; i < n - 1; i += 2) {
		if (arr[i] < arr[i + 1]) {
			if (min > arr[i])
				min = arr[i];
			if (max < arr[i + 1])
				max = arr[i + 1];
		}
		else {
			if (max < arr[i])
				max = arr[i];
			if (min > arr[i + 1])
				min = arr[i + 1];
		}
	}

	if (n & 0x01) {
		if (min > arr[n - 1]) min = arr[n - 1];
		else if (max < arr[n - 1]) max = arr[n - 1];
	}

	return make_pair(max, min);
}

// 分治法
pair<int, int> search(int arr[], int first, int last) {
	if (last - first <= 1) {
		if (arr[first] < arr[last])
			return make_pair(arr[last], arr[first]);
		else 
			return make_pair(arr[first], arr[last]);
	}

	auto left = search(arr, first, first + ((last - first) >> 1));
	auto right = search(arr, first + ((last - first) >> 1) + 1, last);

	int max = left.first, min = left.second;
	if (max < right.first)
		max = right.first;
	if (min > right.second)
		min = right.second;
	return make_pair(max, min);
}

int main() {
	int data[] = { 10, 12, 54, 12, 11, 1, 451, 12, 54, 23, 1254 };
	auto res = findMaxAndMin(data, 11);
	cout << "max = " << res.first << "; min = " << res.second << endl;
	res = findMaxAndMin2(data, 11);
	cout << "max = " << res.first << "; min = " << res.second << endl;
	res = findMaxAndMin3(data, 11);
	cout << "max = " << res.first << "; min = " << res.second << endl;
	res = search(data, 0, 10);
	cout << "max = " << res.first << "; min = " << res.second << endl;
	return 0;
}