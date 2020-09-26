/*
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& inorder, int low, int high, vector<int>& postorder, int first, int last) {
        if (low > high) return nullptr;
        TreeNode* root = new TreeNode(postorder[last]);
        int dis = 0;
        while (inorder[low + dis] != postorder[last]) dis++;
        root->left = buildTree(inorder, low, low + dis - 1, postorder, first, first + dis - 1);
        root->right = buildTree(inorder, low + dis + 1, high, postorder, first + dis, last - 1);
        return root;
    }
};