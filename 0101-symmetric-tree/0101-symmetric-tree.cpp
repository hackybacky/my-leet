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
    bool mirror(TreeNode * root , TreeNode * root2){
        if(!root and !root2){
            return true;
        }
        if(!root or !root2 or root -> val != root2 -> val){
            return false;
        }
        return mirror(root -> left , root2 -> right ) and mirror(root -> right , root2 -> left);
    }
    bool isSymmetric(TreeNode* root) {
        return mirror(root , root);
    }
};