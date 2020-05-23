/**
 * 给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 * 保证base和exponent不同时为0
 * (写个递归实现吧)
 */

class Solution {
public:
    double Power(double base, int exponent) {
        bool flag = true;
        if (exponent < 0) {
            flag = false;
            exponent = -exponent;
        }
        return flag ? power(base, exponent) : 1 / power(base, exponent);
    }

    double power(double base, int exponent) {
        if (exponent == 0)
            return 1;
        double t = power(base, exponent >> 1);
        if (exponent & 0x01)
            return t * t * base;
        else
            return t * t;
    }
};