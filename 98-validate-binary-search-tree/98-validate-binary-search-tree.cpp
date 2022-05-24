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
    TreeNode * r;
    bool recur(TreeNode *root,long min , long max){
        if(!root)return true;
        
        if(root->val<=min or root->val>=max)return false;
        
        
        return recur(root->left,min , root->val) and recur(root->right , root->val , max);
        
        
    }
    bool isValidBST(TreeNode* root) {
        r=root;
        return recur(root,LONG_MIN , LONG_MAX);
    }
};