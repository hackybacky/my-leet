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
    TreeNode* ans;
    bool check(TreeNode*root,int val){
        if(root==nullptr){
            return false;
        }
        if(root->val==val){
            ans=root;
            return true;
        }
        return check(root->left,val) or check(root->right,val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        if(check(root,val)==true){
            return ans;
        }
        return nullptr;
    }
};