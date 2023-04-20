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
    map<int ,pair<int,int>>mp;
    void dfs(TreeNode * root , int cur , int level ){
        
        if(!root)return ;
        if(mp.find(level)==mp.end())mp[level]={cur,cur};
        else {
            mp[level].first=min(mp[level].first,cur);
            mp[level].second=max(mp[level].second,cur);
        }
        dfs(root->left,(long long)2*cur+1,level+1);
        dfs(root->right,(long long)2*cur+2,level+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        dfs(root, 0,0);
        for(auto it:mp){
            ans=max(ans,it.second.second-it.second.first);
        }
        return ans+1;
    }
};