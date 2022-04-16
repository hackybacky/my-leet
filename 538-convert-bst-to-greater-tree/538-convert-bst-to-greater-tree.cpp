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
    
    int giveans(TreeNode*root,bool left , int parent){
        if(root==nullptr)return 0;
        
        int cur =root->val+ giveans(root->right,false,0);
        if(root->left)
        root->left->val = cur+giveans(root->left,true,0);
        if(root->right)
        root->right->val= giveans(root->right,false,0);
        return root->val=cur;
        
    }
    int su=0;
    TreeNode* convertBST(TreeNode* root) {
        if(root){
            convertBST(root->right);
            root->val+=su;
            su=root->val;
            convertBST(root->left);
        }
        return root;
    }
};