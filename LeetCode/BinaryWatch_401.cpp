/**
二进制手表顶部有 4 个 LED 代表 小时（0-11），底部的 6 个 LED 代表 分钟（0-59）。

每个 LED 代表一个 0 或 1，最低位在右侧。



例如，上面的二进制手表读取 “3:25”。

给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

 

示例：

输入: n = 1
返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 

提示：

输出的顺序没有要求。
小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。
超过表示范围（小时 0-11，分钟 0-59）的数据将会被舍弃，也就是说不会出现 "13:00", "0:61" 等时间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-watch
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */


// 巧用二进制
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for (int i = 0; i < 12; i++) {
            if (countOf1(i) == num)
                res.push_back(to_string(i) + ":00");
            else {
                for (int j = 0; j < 60; j++)
                    if (countOf1(i) + countOf1(j) == num)
                        res.push_back(to_string(i) + ":" + (j < 10 ?  "0" : "") + to_string(j));
            }
        }
        return res;
    }

private:
    int countOf1(int num) {
        int cnt = 0;
        while (num) {
            num &= num - 1;
            cnt++;
        }
        return cnt;
    }
};


// 回溯法
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        int start = 0;
        pair<int, int> time(0, 0);
        search(res, num, start, time);
        return res;
    }
private:
    void search(vector<string>& res, int num, int start, pair<int, int>& time) {
        if (num == 0) {
            if (time.first > 11 || time.second > 59) return;
            char str[6];
            sprintf(str, "%d:%02d", time.first, time.second);
            res.push_back(str);
            return;
        }
        for (int i = start; i < 10; i++) {
            auto oldTime = time;
            if (i < 4)
                time.first += hash[i];
            else
                time.second += hash[i];
            search(res, num - 1, i + 1, time);
            time = oldTime;
        }
    }
    
    int hash[10] = { 1, 2, 4, 8, 1, 2, 4, 8, 16, 32 };
};