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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        if(root == q or root == p)return root;
        auto left = lowestCommonAncestor(root -> left , p , q);
        auto right = lowestCommonAncestor(root -> right , p , q);
        if(left and right){
            return root;
        }
        return left ? left : right;
    }
};