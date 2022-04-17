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
    TreeNode *cur=new TreeNode();
    void ans(TreeNode *root){
        if(root==nullptr)return ;
        ans(root->left);
        auto newcur=new TreeNode();
        newcur->val=root->val;
        cur->right=newcur;
        
        cur=cur->right;
        ans(root->right);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        auto n = cur;
        ans(root);
        return n->right;
    }
};