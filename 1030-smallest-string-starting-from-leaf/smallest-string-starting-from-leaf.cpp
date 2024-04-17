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
    void dfs(TreeNode* node,string& ans,string result)
    {
      if (!node) return;
        
       
        result += ('a' + node->val);
        
        
        if (!node->left && !node->right) {
            reverse(result.begin(), result.end());
            if (ans.empty() || result < ans) {
                ans = result;
            }
            return;
        }
        
        
        dfs(node->left, ans, result);
        dfs(node->right, ans, result);
    }
    string smallestFromLeaf(TreeNode* root) {
       
        string result;
        string ans;
        dfs(root,ans,result);
        return ans;
        
    }
};