/**
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于数组的
 * 后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> arr(array.size());
        int i = 0, j = array.size() - 1;
        for (auto& val : array) {
            if (val & 0x01) {
                arr[i++] = val;
            } else {
                arr[j--] = val;
            }      
        }
        copy(arr.begin(), arr.begin() + i, array.begin());
        copy(arr.begin() + i, arr.end(), array.rbegin());
    }
};