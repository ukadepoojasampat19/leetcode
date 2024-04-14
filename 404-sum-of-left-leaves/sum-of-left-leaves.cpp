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
   /* int dfs(TreeNode* node,bool isleft)
    {
       if(!node)
        {
            return 0;
        }
        if(!node->left && !node->right)
        {
            return isleft ? node->val: 0;
        }
        int leftSum=dfs(node->left,true);
        int rightSum=dfs(node->right,false);

        return leftSum+rightSum;
    }*/
    int sumOfLeftLeaves(TreeNode* root) {
        
       /* return dfs(root,false);*/

        if(!root)
        {
            return 0;
        }

        queue<pair<TreeNode*, bool>> q;
        int totalSum=0;
        q.push({root,false});

        while(!q.empty())
        {
            auto [node,isleft]=q.front();
            q.pop();

            if(isleft && !node->left && !node->right)
            {
                totalSum+=node->val;
            }
            if(node->left)
            {
                q.push({node->left,true});
            }
            if(node->right)
            {
                q.push({node->right,false});
            }
        }

        return totalSum;
    }
};