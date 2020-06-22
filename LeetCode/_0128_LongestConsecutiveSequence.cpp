/*
给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set s(nums.begin(), nums.end());
        int ans = 0;
        for (auto& num : s) {
            if (s.find(num - 1) == s.end()) {
                int cnt = 1;
                while (s.find(num + cnt) != s.end()) {
                    cnt++;
                }
                ans = max(cnt, ans);
            }
        }
        return ans;
    }
};