/**
 * 输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
 * 假设输入的前序遍历和中序遍历的结果中都不含重复的数字。例
 * 如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,
 * 2,1,5,3,8,6}，则重建二叉树并返回。
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.empty() || vin.empty() || pre.size() != vin.size())
            return nullptr;
        return reConstruct(pre, vin, 0, pre.size() - 1, 0, vin.size() - 1);
    }

    TreeNode* reConstruct(vector<int>& pre, vector<int>& vin, int first, int last, int left, int right) {
        if (first > last)
            return nullptr;
        TreeNode* root = new TreeNode(pre[first]);
        int cnt = 0;
        while (vin[left + cnt] != pre[first]) cnt++;
        root->left = reConstruct(pre, vin, first + 1, first + cnt, left, left + cnt - 1);
        root->right = reConstruct(pre, vin, first + cnt + 1, last, left + cnt + 1, right);
        return root;
    }
};