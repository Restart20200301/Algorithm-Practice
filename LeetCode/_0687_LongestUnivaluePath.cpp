/**
给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。

注意：两个节点之间的路径长度由它们之间的边数表示。

示例 1:

输入:

              5
             / \
            4   5
           / \   \
          1   1   5
输出:

2
示例 2:

输入:

              1
             / \
            4   5
           / \   \
          4   4   5
输出:

2
注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-univalue-path
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int n = 0;
        univaluePath(root, n);
        return n;
    }
private:
    int univaluePath(TreeNode* root, int& n) {
        if (!root) return 0;
        int l = univaluePath(root->left, n);
        int r = univaluePath(root->right, n);
        int left, right;
        left = right = 0;
        if (root->left && root->left->val == root->val) left = l + 1;
        if (root->right && root->right->val == root->val) right = r + 1;
        n = max(n, left + right);
        return max(left, right);
    }
};