/**
 * 请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为
 * We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
 */

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int cnt = 0;
        for (int i = 0; i < length; i++)
            if (str[i] == ' ') cnt++;
        while (cnt) {
            if (str[--length] == ' ') {
                cnt--;
                str[length + cnt * 2] = '%';
                str[length + cnt * 2 + 1] = '2';
                str[length + cnt * 2 + 2] = '0';
            } else
                str[length + cnt * 2] = str[length];
        }
	}
};