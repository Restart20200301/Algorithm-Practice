/**
 * 一个数出现次数超过了数组大小的一半
 */

template<typename Type>
 Type find(Type* data, int n) {
     Type t;
     int cnt = 0;
     for (int i = 0; i < n; i++) {
         if (cnt == 0) {
             t = data[i];
             i++;
         } else {
             if (t == data[i]) {
                 cnt++;
             } else {
                 cnt--;
             }
         }
     }
     return t;
 }

 #include <iostream>
 using namespace std;
 int main() {
     int data[] = { 1, 5, 7, 5, 4, 5, 4, 5, 5 };
     cout << find(data, 9) << endl;
     return 0;
 }