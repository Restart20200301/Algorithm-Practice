/**
给出二叉树的根节点 root，树上每个节点都有一个不同的值。

如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。

返回森林中的每棵树。你可以按任意顺序组织答案。

 

示例：



输入：root = [1,2,3,4,5,6,7], to_delete = [3,5]
输出：[[1,2,null,4],[6],[7]]
 

提示：

树中的节点数最大为 1000。
每个节点都有一个介于 1 到 1000 之间的值，且各不相同。
to_delete.length <= 1000
to_delete 包含一些从 1 到 1000、各不相同的值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/delete-nodes-and-return-forest
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> deleteSet(to_delete.begin(), to_delete.end());
        root = process(root, res, deleteSet);
        if (root) res.push_back(root);
        return res;
    }
private:
    TreeNode* process(TreeNode* root, vector<TreeNode*>& res, unordered_set<int>& deleteSet) {
        if (!root) return nullptr;
        root->left = process(root->left, res, deleteSet);
        root->right = process(root->right, res, deleteSet);
        if (deleteSet.find(root->val) == deleteSet.end()) return root;
        if (root->left) res.push_back(root->left);
        if (root->right) res.push_back(root->right);
        return nullptr;
    }
};