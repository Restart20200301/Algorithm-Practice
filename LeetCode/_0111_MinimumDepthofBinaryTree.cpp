/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。

示例:

给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度  2.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-depth-of-binary-tree
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


//  dfs
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        int ans = INT_MAX;
        if (root->left) ans = min(minDepth(root->left), ans);
        if (root->right) ans = min(minDepth(root->right), ans);
        return ans + 1;
    }
};

// 
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> que;
        que.emplace(root, 1);
        while (!que.empty()) {
            auto node = que.front().first;
            int depth = que.front().second;
            que.pop();
            if (!node->left && !node->right) return depth;
            if (node->left) que.emplace(node->left, depth + 1);
            if (node->right) que.emplace(node->right, depth + 1);
        }
        return 0;
    }
};