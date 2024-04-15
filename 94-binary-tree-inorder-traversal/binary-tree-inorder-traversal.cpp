/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder_tra(TreeNode* node,vector<int>& result)
    {
        if(!node)
        {
            return;
        }
        inorder_tra(node->left,result);
        result.push_back(node->val);
        inorder_tra(node->right,result);

    }

    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> result;
        inorder_tra(root,result);
        return result;
        
        
    }
};