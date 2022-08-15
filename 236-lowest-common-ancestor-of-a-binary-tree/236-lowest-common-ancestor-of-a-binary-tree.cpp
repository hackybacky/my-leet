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
    TreeNode * lca;
    bool give_me_lca(TreeNode * root , TreeNode *p , TreeNode *q){
        if(!root){
            return false;
        }
        if(root==p or root==q){lca=root;return true;}
        auto flag = give_me_lca(root->left , p , q);
        auto flag2= give_me_lca(root->right,p,q);
        
        if(flag and flag2){
            lca=root;
            return root;
        }
        
        return flag or flag2;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        give_me_lca(root,p,q);
//         if(root==NULL or root==p or root==q)return root;
        
//         auto t = lowestCommonAncestor(root->left,p,q);
//         auto t2= lowestCommonAncestor(root->right,p,q);
        
//         if(t and t2)return root;
        
//         return t?t:t2;
        return lca;
    }
};