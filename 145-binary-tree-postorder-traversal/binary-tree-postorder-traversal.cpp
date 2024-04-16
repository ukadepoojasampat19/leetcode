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
    void  pot(TreeNode* node,vector<int>& temp)
    {
        if(!node)
        {
            return;
        }
        pot(node->left,temp);
        pot(node->right,temp);
        temp.push_back(node->val);


    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> temp;
        pot(root,temp);
        return temp;
    }
};