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
    int ans=0;
    void dfs(TreeNode* root , int level){
        if(!root){
            ans=max(ans,level);
            return ;
        }
        
        dfs(root->left,level+1);
        dfs(root->right,level+1);
        
    }
    int maxDepth(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};