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
    int inorder(TreeNode * root , int cur){
        if(!root)return 0;
        cur = cur * 10 + root -> val;
        if(!root -> right  and !root -> left)return cur;
        int a = 0 , b = 0;
        
        a = inorder(root -> left , cur) ;
        
        b = inorder(root -> right , cur);
        return a + b;
    }
    int sumNumbers(TreeNode* root) {
        
        return inorder(root , 0);
    }
};