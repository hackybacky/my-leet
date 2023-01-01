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
    void flat(TreeNode * root , TreeNode *& prv){
        if(!root)return;
        
        flat(root -> right , prv);
        flat(root -> left , prv);
        root -> right = prv;
        root -> left = NULL;
        prv = root;
        
        
    }
    void flatten(TreeNode* root) {
        TreeNode * prv = NULL;
        flat(root , prv);
    }
};