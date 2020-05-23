/**
 *  1、给定一个整数N，那么N的阶乘N！末尾有多少个0？
 */

 int countOf1First(int n) {
     int cnt = 0;
     for (int i = 1; i <= n; i++) {
         int j = i;
         while (j % 5 == 0) {
             cnt++;
             j /= 5;
         }
     }
     return cnt;
 }

 int countOf1Second(int n) {
     int cnt = 0;
     while (n) {
         n /= 5;
         cnt += n;
     }
     return cnt;
 }

 /**
 *  2、求N！的二进制表示中最低位1的位置。
 */

int lowest1First(int n) {
    int cnt = 0;
    while (n) {
        n >>= 1; // n /= 2
        cnt += n;
    }
    return cnt;
}

// N！含有质因数2的个数，还等于N减去N的二进制表示中1的数目。
int lowest1Second(int n) {
    int t = n;
    int cnt = 0;
    while (t) {
        cnt++;
        t &= (t - 1);
    }
    return n - cnt;
}

#include <iostream>
using namespace std;
int main() {
    int n = 11;
    cout << countOf1First(n) << endl;
    cout << countOf1Second(n) << endl;
    cout << lowest1First(n) << endl;
    cout << lowest1Second(n) << endl;
}