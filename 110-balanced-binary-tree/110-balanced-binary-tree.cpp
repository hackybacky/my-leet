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
    bool flag=true;
    int dfs(TreeNode * root){
        if(!root)return 0;
        int l =0,r=0;
        l=1+dfs(root->left);
        r= 1+ dfs(root->right);
        if(abs(l-r)>1)flag=false;
        
        return max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return flag;
    }
};