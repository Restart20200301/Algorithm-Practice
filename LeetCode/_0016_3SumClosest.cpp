/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
 

提示：

3 <= nums.length <= 10^3
-10^3 <= nums[i] <= 10^3
-10^4 <= target <= 10^4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int difference = 3 * 1e3;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int a = nums[i];
            int p = i + 1;
            int q = nums.size() - 1;
            while (p < q) {
                int b = nums[p];
                int c = nums[q];
                if (b + c < target - a) {
                    p++;
                    while (p < q && nums[p] == nums[p - 1]) p++;
                    difference = abs(a + b + c - target) < abs(difference - target) ? (a + b + c) : difference;
                } else if (b + c > target - a) {
                    q--;
                    while (p < q && nums[q] == nums[q + 1]) q--;
                    difference = abs(a + b + c - target) < abs(difference - target) ? (a + b + c) : difference;
                } else return target;
            }
        }
        return difference;
    }
};