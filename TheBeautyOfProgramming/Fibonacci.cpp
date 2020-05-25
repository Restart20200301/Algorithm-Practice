// 递归版本
int Fibonacci(int n) {
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	else return Fibonacci(n - 1) + Fibonacci(n - 2);
}

// 递归优化(存储计算结果，避免重复计算)
int Fibonacci2(int n, int* data) {
	if (n >= 0 && data[n] != -1) return data[n];
	if (n <= 0) { data[0] = 0; return 0; }
	else if (n == 1) { data[1] = 1; return 1; }
	data[n] = Fibonacci2(n - 1, data) + Fibonacci2(n - 2, data);
	return data[n];
}

// 迭代
int Fibonacci3(int n) {
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	int a = 0, b = 1;
	int c = n - 1;
	while (c--) {
		int t = a + b;
		a = b;
		b = t;
	}
	return b;
}


#include <iostream>
using namespace std;

int main() {
    int n = 20;
	cout << Fibonacci(n) << endl;
	int *data = new int[1024];
	for (int i = 0; i < 1024; i++) data[i] = -1;
	cout << Fibonacci2(n, data) << endl;
	delete data;
	cout << Fibonacci3(n) << endl;
	return 0;
}