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
    vector<TreeNode * > node;
    int h;
    int depth(TreeNode *root){
        if(!root)return 0;
        
        int d =1+max(depth(root->right),depth(root->left));
        if(d==h)node.push_back(root);
        return d;
    }
    bool check(TreeNode * root, TreeNode * s){
        if(!s and !root)return true;
        if(!s or !root or root->val !=s->val)return false;
        return check(root->left,s->left) and check(root->right,s->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        h= depth(subRoot);
        depth(root);
        for(auto it : node){
            if(check(it,subRoot))return true;
        }
        return false;
    }
};