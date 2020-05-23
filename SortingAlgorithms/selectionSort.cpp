#include <iostream>
using namespace std;

template<typename Type>
void selectionSort(Type* data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (data[i] > data[j]) swap(data[i], data[j]);
        }
    }
}

int main() {
    int data[] = { 12, 1, 25, 75, 12, 45, 1, 65, 45, 26, 12, 45, 14, 12, 14 };
    selectionSort(data, 15);
    for (int i = 0; i < 15; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
} 