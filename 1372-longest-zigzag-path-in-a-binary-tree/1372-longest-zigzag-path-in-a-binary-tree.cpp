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
    int ans = INT_MIN;
    void dfs(TreeNode * root , int lvl , char d ){
        // ans = max(ans , lvl);
        if(!root)return ;
        if(d == 'r'){
            if(root -> left){
                ans = max(ans , lvl + 1);
                dfs(root -> left , lvl + 1 , 'l' );
            }
            if(root -> right){
                dfs(root -> right , 1 , 'r');
            }
        }
        else{
            if(root -> right){
                ans = max(ans , lvl + 1);
                dfs(root -> right , lvl + 1 , 'r');
            }
            if(root -> left){
                dfs(root -> left , 1 , 'l');
            }
        }
        ans = max(ans , lvl);
    }
    int longestZigZag(TreeNode* root) {
        dfs(root , 0, 'l') , dfs(root , 0 , 'r');
        return ans;
    }
};