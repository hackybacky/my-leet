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
    map<TreeNode*,int>dis;
    void dfs(TreeNode *root,TreeNode * par){
        if(root==nullptr)return;
        dis[root]=dis[par]+1;
        dfs(root->left,root);
        dfs(root->right,root);
        
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root,0);
        int ans=0;
        int mini=INT_MIN;
        for(auto it: dis)mini=max(it.second,mini);
        for(auto it : dis )(it.second==mini?ans+=it.first->val:0);
        // cout<<mini<<endl;
        
        return ans;
    }
};