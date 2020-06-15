/**
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize < 1) return "";
    if (strsSize == 1) return strs[0];
    int len = 0;
    for (; strs[0][len] && strs[1][len] && strs[0][len] == strs[1][len]; len++) ;
    for (int i = 2; i < strsSize; i++) {
        int j;
        for (j = 0; strs[i][j] && strs[0][j] == strs[i][j] && j < len; j++) ;
        len = j;
    }
    strs[0][len] = 0;
    return strs[0];
}