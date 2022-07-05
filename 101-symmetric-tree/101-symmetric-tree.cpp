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
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        queue<TreeNode *>a ,b;
        a.push(root->left);
        b.push(root->right);
        while(!a.empty() and !b.empty()){
            auto left = a.front();
            a.pop();
            auto right = b.front();
            b.pop();
            if(!left and right)return false;
            else if(left and !right)return false;
            else if(left and right and left->val !=right->val)return false;
            else if(!left and !right) continue;
            a.push(left->left);
            a.push(left->right);
            b.push(right->right);
            b.push(right->left);
            
        }
        if(!a.empty() or !b.empty())return false;
        return true;
    }
};