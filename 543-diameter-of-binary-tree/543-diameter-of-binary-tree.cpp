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
    int dia;
    int recur(TreeNode *root){
        if(!root)return 0;
        int l=0, r=0;
        if(root->left)l=1+recur(root->left);
        if(root->right)r=1+recur(root->right);
        dia=max(dia,l+r);
        return max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        recur(root);
        return dia;
    }
};