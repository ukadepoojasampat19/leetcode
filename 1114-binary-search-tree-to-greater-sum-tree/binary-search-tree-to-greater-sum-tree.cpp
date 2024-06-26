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
    void  bst_greater(TreeNode* temp,vector<int> &store)
    {
        if (temp == nullptr) return;

        bst_greater(temp->left,store);
        int value = temp->val;
        int sum=0;
        for(int i=0;i<store.size();i++)
        {
            if(store[i] >= value)
            {
                sum += store[i];
            }
        }
        temp->val = sum;
        bst_greater(temp->right,store);
        
    }
    void  bst(TreeNode* temp,vector<int> &store)
    {
        if (temp == nullptr) return;
        bst(temp->left,store);
        store.push_back(temp->val);
        bst(temp->right,store);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> store;
        
        bst(root,store);
       
        bst_greater(root,store);
        return root;
    }
};