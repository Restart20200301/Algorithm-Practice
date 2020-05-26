#include <iostream>
using namespace std;

template<typename Type>
void shellSort(Type* data, int n) {
    for (int i = (n >> 1); i > 0; i >>= 1) {
        for (int j = i; j < n; j++) {
            int k = j;
            while (k - i >= 0 && data[k] < data[k - i]) {
                swap(data[k], data[k - i]);
                k -= i;
            }
        }
    }
}

int main() {
    int data[] = { 12, 1, 25, 75, 12, 45, 1, 65, 45, 26, 12, 45, 14, 12, 14 };
    shellSort(data, 15);
    for (int i = 0; i < 15; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
} 