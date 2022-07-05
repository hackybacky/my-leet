/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or root==p or root==q)return root;
        
        auto t = lowestCommonAncestor(root->left,p,q);
        auto t2= lowestCommonAncestor(root->right,p,q);
        
        if(t and t2)return root;
        
        return t?t:t2;
    }
};