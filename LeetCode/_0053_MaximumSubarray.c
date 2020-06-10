/**
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

//  动态规划 (dp[i] 代表以i为结束的子序列的最大和)
#define MAX(a, b) \
    (a) > (b) ? (a) : (b)

int maxSubArray(int* nums, int numsSize) {
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
       if (nums[i - 1] > 0) nums[i] += nums[i - 1];
       max = MAX(max, nums[i]);
    }
    return max;
}

// 暴力求解
// .... 暂时不想写了  在练习动态规划