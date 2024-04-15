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
int dfs(TreeNode* node,int pathSum)
{
    /*(!node)
    {
        return;
    }
    sum+=node->val;
    dfs(node->left,sum,value);
    value.push_back(sum);
    sum-=node->left->val;
    dfs(node->right,sum,value);*/

    if(!node)
    {
        return 0;
    }
    pathSum=pathSum * 10 + node->val;

    if(!node->left && !node->right)
    {
        return pathSum;
    }

    int leftsum=dfs(node->left,pathSum);
    int rightsum=dfs(node->right,pathSum);

    return leftsum+rightsum;

}
    int sumNumbers(TreeNode* root) {
    
    
        return dfs(root,0);
        
    }
};