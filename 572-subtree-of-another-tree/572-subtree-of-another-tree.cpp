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
    bool ans;
    TreeNode * o;
    map<pair<TreeNode *,TreeNode*> , bool > dp;
    bool recur(TreeNode *root, TreeNode * s){
        if(!s and !root)return true;
        if(!s or !root)return false;
        if(dp.find({root,s})!=dp.end())return dp[{root,s}];
        bool ans;
        if(s->val==root->val){
            ans= (recur(root->left,s->left) and recur(root->right,s->right)) |
                (recur(root->left,o)) | recur(root->right,o);
                ;
        }
        else{
            ans= recur(root->left , o) | recur(root->right,o);
        }
        return dp[{root,s}]=ans;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        o=subRoot;
        return recur(root,subRoot);
    }
};