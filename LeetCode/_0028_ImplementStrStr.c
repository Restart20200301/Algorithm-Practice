/*
实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1:

输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:

输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:

当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。

对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

// 仿java1.8 java indexOf()
int strStr(char* haystack, char* needle) {
    int sublen = strlen(needle);
    if (sublen == 0) return 0;
    int len = strlen(haystack);
    for (int i = 0; i <= len - sublen; ) {
        while (i <= len - sublen && haystack[i] != needle[0]) i++;
        if (i <= len - sublen) {
            int j = 1;
            for (; j < sublen && haystack[i + j] == needle[j]; j++) ;
            if (j == sublen) return i;
            i++;
        }
    }
    return -1;
}


// KMP
void initNextArray(int* nextArray, char* needle, int len) {
    nextArray[0] = -1;
    int i = 0, j = -1;
    while (i < len - 1) {
        if (j == -1 || needle[i] == needle[j]) {
            i++; j++;
            nextArray[i] = j;
        } else 
            j = nextArray[j];
    }
}

int strStr(char* haystack, char* needle) {
    int sublen = strlen(needle);
    if (sublen == 0) return 0;
    int len = strlen(haystack);
    int* nextArray = malloc(sizeof(int) * sublen);
    initNextArray(nextArray, needle, sublen);
    int i = 0;
    int j = 0;
    while (i < len && j < sublen) {
        if (j == -1 || haystack[i] == needle[j]) {
            i++; j++;
        } else {
            j = nextArray[j];
        }
    }
    free(nextArray);
    if (j == sublen) return i - j;
    else return -1;
}