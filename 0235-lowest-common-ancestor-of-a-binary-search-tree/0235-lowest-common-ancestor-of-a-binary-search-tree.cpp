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
        int val = root -> val;
        int curl = min(p -> val , q -> val);
        int curr = max(p -> val , q -> val);
        if(val >= curl and val <= curr)return root;
        if(val >= curr)return lowestCommonAncestor(root -> left , p , q);
        return lowestCommonAncestor(root -> right , p , q);
    }
};