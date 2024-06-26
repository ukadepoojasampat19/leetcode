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
    int sum = 0; // to keep track of the cumulative sum
    
    void bst_greater(TreeNode* node) {
       if(node == nullptr) return;

       //first travel right
       bst_greater(node->right);

       sum += node->val;
       node->val = sum;

       //travel left
       bst_greater(node->left);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
       bst_greater(root);
       return root;
    }
};
