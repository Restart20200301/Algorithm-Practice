/**
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 * 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总
 * 共有多少种方法？
 */

class Solution {
public:
    int rectCover(int number) {
        if (number <= 3)
            return number;
        int prev = 2;
        int next = 3;
        number -= 3;
        while (number--) {
            int sum = prev + next;
            prev = next;
            next = sum;
        }
        return next;
    }
};