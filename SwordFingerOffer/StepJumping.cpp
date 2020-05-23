/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个
 * n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 */

class Solution {
public:
    int jumpFloor(int number) {
        if (number <= 3)
            return number;
        int prev = 2, next = 3;
        number -= 3;
        while (number--) {
            int sum = prev + next;
            prev = next;
            next = sum;
        }
        return next;
    }
};