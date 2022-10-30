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
    int giveans(TreeNode *root){
        if(root==nullptr)return INT_MAX;
        
        int ans = giveans(root->left);
        K--;
        if(K==0)return root->val;
        int ans2 = giveans(root->right);
        return min(ans , ans2);
    }
    int kthSmallest(TreeNode* root, int k) {
        K=k;
        return    giveans(root);
        return ans;
    }
};