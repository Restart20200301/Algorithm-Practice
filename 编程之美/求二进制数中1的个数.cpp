#include <iostream>
using namespace std;

int Count1(int);
int Count2(int);
int Count3(int);

int main() {
    int n = 15645;
    cout << Count1(n) << endl;
    cout << Count2(n) << endl;
    cout << Count3(n) << endl;
    return 0;
}

int Count1(int n) {
    int num = 0;
    while (n) {
        if (n % 2 == 1)
            num++;
        n /= 2;
    }
    return num;
}

int Count2(int n) {
    int num = 0;
    while (n) {
        num += (n & 0x01);
        n >>= 1;
    } 
    return num;
}

int Count3(int n) {
    int num = 0;
    while (n) {
        n &= (n - 1);
        num++;
    }
    return num;
}