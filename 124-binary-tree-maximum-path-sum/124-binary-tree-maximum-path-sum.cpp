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
    
    int ans=INT_MIN;
    int  recur( TreeNode * root ){
        if(!root)return 0;
       
        int a = recur(root->left);
        int b = recur(root->right);
        int cv=root->val;
        ans=max({ans,a+cv , b+cv, cv , cv+a+b});
        return  max(cv+max({a,b}),cv);
        
    }
    int maxPathSum(TreeNode* root) {
        recur(root);
        return ans;
    }
};