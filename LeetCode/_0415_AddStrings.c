/**
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：

num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

 // 解法有点儿费事儿了。其实不需要翻转字符串的。

void reverse(char* str, int p, int q) {
    while (p < q) {
        char t = str[p];
        str[p] = str[q];
        str[q] = t;
        p++; q--;
    }
}


char* addStrings(char* num1, char* num2) {
    int len1 = strlen(num1);
    reverse(num1, 0, len1 - 1);
    int len2 = strlen(num2);
    reverse(num2, 0, len2 - 1);
    int len = (len1 > len2 ? len1 : len2) + 2; // +2原因: 可能进位。C字符串需要\0
    char* res = malloc(len);
    memset(res, 0, len);
    int t = 0;
    int pos = 0;
    while (*num1 || *num2 || t) {
        int n = 0;
        if (*num1) { n += *num1 - '0'; num1++; }
        if (*num2) { n += *num2 - '0'; num2++; }
        n += t;
        res[pos++] = n % 10 + '0';
        t = n / 10;
    }
    reverse(res, 0, pos - 1);
    return res;
}