/*
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:

输入: [1,2,3]

       1
      / \
     2   3

输出: 6
示例 2:

输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-maximum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a, b) \
    (a) > (b) ? (a) : (b)

int pathSum(struct TreeNode* root, int* max) {
    if (!root) return 0;
    int l = pathSum(root->left, max);
    l = MAX(0, l);
    int r = pathSum(root->right, max);
    r = MAX(0, r);
    int t = l + r + root->val;
    *max = MAX(*max, t);
    t = MAX(l, r);
    return t + root->val;
}

int maxPathSum(struct TreeNode* root) {
    int max = INT_MIN;
    pathSum(root, &max);
    return max;
}