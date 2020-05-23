// 小根堆。   从大到小排序

#include <iostream>
using namespace std;

template<typename Type>
void minHeapify(Type* data, int start, int end) {
    int dad = start;
    int son = start * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && data[son] > data[son + 1])
            son++;
        if (data[dad] < data[son])
            return;
        else {
            std::swap(data[dad], data[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

template<typename Type>
void buildMinHeap(Type* data, int n) {
    for (int i = (n >> 1) - 1; i >= 0; i--)
        minHeapify(data, i, n - 1);
}

template<typename Type>
void heapSort(Type* data, int n) {
    buildMinHeap(data, n);

    for (int i = n - 1; i > 0; i--) {
        swap(data[0], data[i]);
        minHeapify(data, 0, i - 1);
    }
}

int main() {
    int data[] = { 12, 1, 25, 75, 12, 45, 1, 65, 45, 26, 12, 45, 14, 12, 14 };
    heapSort(data, 15);
    for (int i = 0; i < 15; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}