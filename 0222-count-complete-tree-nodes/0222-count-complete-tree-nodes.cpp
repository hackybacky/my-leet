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
    int height(TreeNode * root){
        if(!root){
            return 0;
        }
        
        return 1 + max(height(root -> left) , height(root -> right));
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        TreeNode * cur = root;
        int hr = height(root -> right);
        int hl = height(root -> left);
        int ans = 0;
        if(hr == hl){
            
            ans = (1 << hl)  + countNodes(root -> right);
        }
        else{
        
            ans = (1 << hr) + countNodes(root -> left);
        }
        
        return ans ;
    }
};