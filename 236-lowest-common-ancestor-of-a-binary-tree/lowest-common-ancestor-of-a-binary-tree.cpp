class Solution {
public:
    bool lsubtree(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL)
        return false;
        if(root==p || root==q)
        return true;
        bool l=lsubtree(root->left,p,q);
        bool r=lsubtree(root->right,p,q);
        if(l==true || r==true)
        return true;
        return false;
    }
    bool rsubtree(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL)
        return false;
        if(root==p || root==q)
        return true;
        bool l=rsubtree(root->left,p,q);
        bool r=rsubtree(root->right,p,q);
        if(l==true || r==true)
        return true;
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
        return NULL;
        if(root==p || root==q)
        return root;
        bool l=lsubtree(root->left,p,q);
        bool r=rsubtree(root->right,p,q);
        if(l==true && r==true)
        return root;
        TreeNode* a=lowestCommonAncestor(root->left,p,q);
        if(a)
        return a;
        TreeNode* b=lowestCommonAncestor(root->right,p,q);
        if(b)
        return b;
        return NULL;
    }
};