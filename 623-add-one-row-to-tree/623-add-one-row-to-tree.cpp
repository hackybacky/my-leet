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
    void dfs(TreeNode * root , int val , int depth){
        if(!root)
            return;
        if(depth == 2){
            auto left = root -> left ;
            auto rigth = root -> right;
            
            root -> left = new TreeNode(val , left  , NULL);
            
            root -> right = new TreeNode(val);
            root -> right -> right = rigth;
        }
        
        dfs(root -> left , val , depth - 1);
        dfs(root -> right , val ,depth - 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            auto n= new TreeNode(val , root  , nullptr);
            root = n;
        }
        else
        dfs(root , val , depth);
        
        return root;
    }
};