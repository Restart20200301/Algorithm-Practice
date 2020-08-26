/*
给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。

示例:

输入: [4, 6, 7, 7]
输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
说明:

给定数组的长度不会超过15。
数组中的整数范围是 [-100,100]。
给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-subsequences
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        dfs(ans, 0, INT_MIN, nums, t);
        return ans;
    }
private:
    void dfs(vector<vector<int>>& ans, int cur, int last, vector<int>& nums, vector<int>& t) {
        if (cur == nums.size()) {
            if (t.size() >= 2) ans.push_back(t);
            return;
        }
        if (nums[cur] >= last) {
            t.push_back(nums[cur]);
            dfs(ans, cur + 1, nums[cur], nums, t);
            t.pop_back();
        }
        if (nums[cur] != last) dfs(ans, cur + 1, last, nums, t);
    }
};