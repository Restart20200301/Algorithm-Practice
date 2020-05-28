/**
394. 字符串解码
给定一个经过编码的字符串，返回它解码后的字符串。

编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。

你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。

此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例:

s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
 */


class Solution {
public:
    string decodeString(string s) {
        vector<string> stk;
        int pos = 0;
        while (pos < s.size()) {
            char c = s[pos];
            if (isdigit(c)) {
                stk.push_back(getDigits(s, pos));
            } else if (c == '[' || isalpha(c)) {
                pos++;
                stk.push_back(string(1, c));
            } else if (c == ']') {
                vector<string> v;
                while (stk.back() != "[") {
                    v.push_back(stk.back());
                    stk.pop_back();
                }
                stk.pop_back();
                reverse(v.begin(), v.end());
                string t = getString(v);
                int cnt = atoi(stk.back().c_str());
                stk.pop_back();
                string tt = "";
                while (cnt--) {
                    tt += t;
                }
                stk.push_back(tt);
                pos++;
            }
        }

        return getString(stk);
    }

private:
    string getDigits(string& s, int& pos) {
        int begin = pos;
        while (isdigit(s[pos]))
            pos++;
        return s.substr(begin, pos - begin);
    }

    string getString(vector<string>& v) {
        string res;
        for (auto& str : v)
            res += str;
        return res;
    }
};