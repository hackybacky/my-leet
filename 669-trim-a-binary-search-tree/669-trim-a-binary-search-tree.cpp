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
    void trim(TreeNode *root ,TreeNode *parent,int dir,  int low , int high){
        
        if(root==nullptr)return ;
        if(root->val<low or root->val>high){
            if(root->left){
                if(dir){
                    parent->left=root->left;
                    if(root->left!=NULL)
                    root->left->right=root->right;
                }
                else{
                    parent->right=root->left;
                    if(root->left)
                    root->left->right=root->right;
                } 
                if(root->left)
                trim(root->left->left,root->left,1,low,high);
                trim(root->right,root->left,0,low,high);
                    
            }
            else{
                if(dir){
                    parent->left=root->right;
                    if(root->right)
                    root->right->left=root->left;
                }
                else {
                    parent->right=root->right;
                    if(root->right)
                    root->right->left=root->left;
                    
                }
                if(root->right)
                trim(root->right->left,root->right,1,low,high);
                    trim(root->right->right,root->right,0,low,high);
            }
        }
        
        else {
            
            trim(root->left,root,1,low ,high);
            trim(root->right,root,1,low,high);
        }
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root==nullptr)return nullptr;
        if(root->val>=low and root->val<=high){
            root->left= trimBST(root->left,low,high);
            root->right=trimBST(root->right,low,high);
            return root;
        }
        if(root->val<low){
            return trimBST(root->right,low,high);
        }
        return trimBST(root->left,low,high);
    }
};