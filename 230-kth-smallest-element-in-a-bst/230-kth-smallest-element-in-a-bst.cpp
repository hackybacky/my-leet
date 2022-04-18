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
    int K;
    int ans;
    void giveans(TreeNode *root ){
        if(root==nullptr)return ;
        
        giveans(root->left);
        K--;
        if(K==0){ans=root->val;return;}
        giveans(root->right);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        K=k;
        giveans(root);
        return ans;
    }
};