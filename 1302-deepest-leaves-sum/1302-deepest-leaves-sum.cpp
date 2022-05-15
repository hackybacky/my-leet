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
    int d;
    int ans;
    int dfs(TreeNode *root,int dis,bool flag){
        // if(flag)cout<<d<<" "<<dis<<endl;
       
        if(root==nullptr)return dis;
        
         return max(dfs(root->left,dis+1,flag),
        dfs(root->right,dis+1,flag));
        
    }
    void dfs2(TreeNode *root , int dis){
        if(root==nullptr)return ;
       
        if(dis==d-1)ans+=root->val;
        dfs2(root->left,dis+1);
        dfs2(root->right,dis+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        d=dfs(root,0,false);
        
        dfs2(root,0);
        
        
        return ans;
    }
};