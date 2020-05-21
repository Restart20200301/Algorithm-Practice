/**
 *  给定一个十进制正整数N，写下从1开始，到N的所有整数，然后数一下其中出现的所有“1”的个数。
 */

//  1、写一个函数f(N)，返回1到N之间出现的“1”的个数，比如f(12) = 5；
// (1)
unsigned int count1InAInteger(unsigned int n) {
    unsigned int cnt = 0;
    while (n) {
        cnt += (n % 10 == 1) ? 1 : 0;
        n /= 10;
    }
    return cnt;
}

unsigned int func(unsigned int n) {
    unsigned int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cnt += count1InAInteger(i);
    }
    return cnt;
}


// (2)
unsigned int sum1s(unsigned int n) {
    unsigned int cnt = 0;
    unsigned int factor = 1;
    
    unsigned int low = 0;
    unsigned int cur = 0;
    unsigned int high = 0;

    while (n / factor) {
        low = n - n / factor * factor;
        cur = (n / factor) % 10;
        high = n / factor / 10;

        if (cur == 0) {
            cnt += high * factor;
        } else if (cur == 1) {
            cnt += high * factor + low + 1;
        } else {
            cnt += (high + 1) * factor;
        } 
        factor *= 10;
    }
    return cnt;
}


#include <iostream>
using namespace std;

int main() {
    int n = 100000;
    cout << func(n) << endl;
    cout << sum1s(n) << endl;
    return 0;
}