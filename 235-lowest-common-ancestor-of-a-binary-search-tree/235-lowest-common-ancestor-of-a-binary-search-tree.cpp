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
    TreeNode * ans;
    void d(TreeNode * root , TreeNode * p , TreeNode* q){
        if(!root)return ;
        
        if(root->val<=q->val and root->val >=p->val){
            ans=root;
            return;
        }
        d(root->right,p,q);
        d(root->left,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val)swap(p,q);
        d(root,p,q);
        return ans;
    }
};