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
    void revert( TreeNode *root){
        if(!root)return;
        
        auto dummy= root->left;
        root->left=root->right;
        root->right=dummy;
        revert(root->right);
        revert(root->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        auto h=root;
        revert(root);
        return h;
        
    }
};