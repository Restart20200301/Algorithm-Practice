/*
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。

 

例如，给定三角形：

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

 

说明：

如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.size());
        dp[0] = triangle[0][0];
        for (decltype(triangle.size()) i = 1, len = triangle.size(); i < len; ++i) {
            dp[i] = dp[i - 1] + triangle[i][i];
            for (decltype(triangle.size()) j = i - 1; j > 0; --j)
                dp[j] = triangle[i][j] + min(dp[j - 1], dp[j]);
            dp[0] += triangle[i][0]; 
        }
        return *min_element(dp.begin(), dp.end());
    }
};