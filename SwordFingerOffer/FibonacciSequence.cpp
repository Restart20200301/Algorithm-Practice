/**
 * 大家都知道斐波那契数列，现在要求输入一个整数n，
 * 请你输出斐波那契数列的第n项（从0开始，第0项为0）。
 * n<=39
 */

class Solution {
public:
    int Fibonacci(int n) {
        if (n < 2)
            return n;
        int prev = 0;
        int next = 1;
        while (--n) {
            int sum = prev + next;
            prev = next;
            next = sum;
        }
        return next;
    }
};