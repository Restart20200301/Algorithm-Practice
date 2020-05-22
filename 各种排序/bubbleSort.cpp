#include <iostream>
using namespace std;

template<typename Type>
void bubbleSort(Type* data, int n) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                swap(data[j], data[j + 1]);
                flag = false;
            }
        }
        if (flag) break;
    }
}

int main() {
    int data[] = { 12, 1, 25, 75, 12, 45, 1, 65, 45, 26, 12, 45, 14, 12, 14 };
    bubbleSort(data, 15);
    for (int i = 0; i < 15; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
} 