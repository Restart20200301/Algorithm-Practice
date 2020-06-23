/*
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

 

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
 

提示：

每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string addBinary(const string& a, const string& b) {
        string ans;
        int posA = a.size() - 1;
        int posB = b.size() - 1;
        int carry = 0;
        while (posA >= 0 || posB >= 0 || carry > 0) {
            if (posA >= 0) carry += a[posA--] - '0';
            if (posB >= 0) carry += b[posB--] - '0';
            ans += to_string(carry & 0x01);
            carry >>= 1; 
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};