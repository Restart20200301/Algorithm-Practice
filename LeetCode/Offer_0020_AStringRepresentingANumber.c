/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，字符串"+100"、"5e2"、"-123"、
"3.1416"、"-1E-16"、"0123"都表示数值，但"12e"、"1a3.14"、"1.2.3"、"+-5"及"12e+5.4"都不是。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

void skipSpace(char** s) {
    while (**s && isspace(**s)) (*s)++;
}

bool getUInt(char** s) {
    bool flag = **s && isdigit(**s);
    while (**s && isdigit(**s)) (*s)++;
    return flag;
}

bool getInt(char** s) {
    if (**s && (**s == '+' || **s == '-')) (*s)++;
    return getUInt(s);
}

bool isNumber(char* s){
    skipSpace(&s);
    bool flag = getInt(&s);
    if (*s && *s == '.') {
        s++;
        flag = getUInt(&s) || flag;
    }
    if (*s && *s == 'e' || *s == 'E') {
        s++;
        flag = flag && getInt(&s);
    }
    skipSpace(&s);
    return flag && !*s;
}

