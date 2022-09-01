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
    int recur(TreeNode * root , int maxi ){
        if(!root)return 0;
        int cur =0;
        if(maxi<=root->val)cur++;
        
        cur += recur(root->left , max(maxi,root->val)) + recur(root->right , max(maxi,root->val));
        
        return cur;
        
    }
    int goodNodes(TreeNode* root , int maxi=INT_MIN) {
        
        if(!root)return 0;
        int cur =0;
        if(maxi<=root->val)cur++;
        
        cur += goodNodes(root->left , max(maxi,root->val)) + goodNodes(root->right , max(maxi,root->val));
        
        return cur;
        
    }
};