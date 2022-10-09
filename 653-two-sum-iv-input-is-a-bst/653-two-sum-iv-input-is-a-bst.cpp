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
    bool search(TreeNode * node , int x ){
        if(!node)
            return false;
        if(node -> val == x){
            return true;
        }
        bool ans = false;
        if(node -> val > x){
            ans = search(node -> left , x);
        }
        else{
            ans = search(node -> right , x);
        }
        return ans;
        
        
    }
    TreeNode * r;
    bool dfs(TreeNode * node , int k){
        if(!node){
            return false;
        }
        
        int x = k - node -> val;
        if(search(r , x) and x != node -> val){
            return true;
        }
        return dfs(node -> left , k) |  dfs(node -> right , k);
    }
    bool findTarget(TreeNode* root, int k) {
        r = root;
        return dfs(root , k);
    
    }
};