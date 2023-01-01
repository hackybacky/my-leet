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
    bool isValidBST(TreeNode* root , long maxi = 1e10  , long  mini = -1e10) {
        
        if(!root)return true;
        
        int val = root -> val;
        if(val >= maxi or mini >= val)return false;
     return    isValidBST(root -> left , val , mini ) & isValidBST(root -> right , maxi , val);
    }
};