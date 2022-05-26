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
    map<TreeNode * , int > dp;
    int ans=INT_MIN;
    int  recur( TreeNode * root ){
        if(!root)return 0;
        // if(dp.find(root)!=dp.end())return dp[root];
        int a = recur(root->left);
        int b = recur(root->right);
        int cv=root->val;
        ans=max({ans,a+cv , b+cv, cv , cv+a+b});
        return  dp[root]=max(cv+max({a,b}),cv);
        
    }
    int maxPathSum(TreeNode* root) {
        recur(root);
        return ans;
    }
};