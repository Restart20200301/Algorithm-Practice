#include <iostream>
using namespace std;

template<typename Type>
int paritition(Type* data, int low, int high) {
    while (low < high) {
        while (low < high && data[low] <= data[high]) high--;
        if (low < high) { swap(data[low], data[high]); low++; }
        while (low < high && data[high] >= data[low]) low++;
        if (low < high) { swap(data[high], data[low]); high--; }
    }
    return low;
}

template<typename Type>
void quickSort(Type* data, int low, int high) {
    if (low < high) {
        int pivot = paritition(data, low, high);
        quickSort(data, low, pivot - 1);
        quickSort(data, pivot + 1, high);
    }
}

template<typename Type>
void quickSort(Type* data, int n) {
    quickSort(data, 0, n - 1);
}

int main() {
    int data[] = { 12, 1, 25, 75, 12, 45, 1, 65, 45, 26, 12, 45, 14, 12, 14 };
    quickSort(data, 15);
    for (int i = 0; i < 15; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
} 