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
    void dfs(TreeNode* node,int val,int depth,int level)
     {
         if(!node)
         {
            return;
         }

        if(level < depth-1)
        {
            dfs(node->left,val,depth,level+1);
            dfs(node->right,val,depth,level+1);
        }
        else
        {
            TreeNode* temp=node->left;
            node->left=new TreeNode(val);
            node->left->left=temp;

            temp=node->right;
            node->right=new TreeNode(val);
            node->right->right=temp;
        }
     }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
       if(depth == 1)
       {
         TreeNode* ptr=new TreeNode(val);
         ptr->left=root;
         return ptr;
       }
       int level=1;
       dfs(root,val,depth,level);
       return root;
    }
};