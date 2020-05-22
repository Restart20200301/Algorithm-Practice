// 求两个数的最大公约数

// (1)
int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

// (2)
int gcd2(int x, int y) {
    if (x < y)
        return gcd2(y, x);
    if (y == 0)
        return x;
    else
        return gcd(x - y, y);
}

// (3)
inline bool isEven(int x) {
    return !(x & 0x01);
}

int gcd3(int x, int y) {
    if (x < y)
        return gcd3(y, x);
    if (y == 0)
        return x;
    else {
        if (isEven(x)) {
            if (isEven(y))
                return (gcd3(x >> 1, y >> 1) << 1);
            else
                return gcd3(x >> 1, y);
        } else {
            if (isEven(y))
                return gcd3(x, y >> 1);
            else
                return gcd3(y, x - y);
        }
    }
}


#include <iostream>
using namespace std;

int main() {
    int a = 560, b = 78200;
    cout << gcd(a, b) << endl;
    cout << gcd2(a, b) << endl;
    cout << gcd3(a, b) << endl;
    return 0;
}