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
    TreeNode* sortedbalaced_tree(vector<int> &store,int st,int ed)
    {
        if(st > ed) return nullptr;

        int mid = st + (ed - st)/2;
        TreeNode* root = new TreeNode(store[mid]);
        root->left = sortedbalaced_tree(store,st,mid-1);
        root->right = sortedbalaced_tree(store,mid+1,ed);

        return root;

    }
    void inordertravesal(TreeNode* node,vector<int> &store)
    {
        if(node == nullptr) return;
        inordertravesal(node->left,store);
        store.push_back(node->val);
        inordertravesal(node->right,store);
    }
    TreeNode* balanceBST(TreeNode* root) {

        vector<int> store;
        inordertravesal(root,store);
        return sortedbalaced_tree(store,0,store.size()-1);
        
    }
};