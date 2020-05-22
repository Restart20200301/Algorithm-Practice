#include <iostream>
using namespace std;

template<typename Type>
void insertSort(Type* data, int n) {
    for (int i = 1; i < n; i++) {
        int j = i - 1; Type t = data[i];
        while (j >= 0 && data[j] < t) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = t;
    }
}

int main() {
    int data[] = { 12, 1, 25, 75, 12, 45, 1, 65, 45, 26, 12, 45, 14, 12, 14 };
    insertSort(data, 15);
    for (int i = 0; i < 15; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
} 