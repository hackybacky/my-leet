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
    int getDiff(TreeNode * root , TreeNode *& prev){
        if(! root){
            return INT_MAX;
        }
        
        int ans = getDiff(root -> left , prev);
        if(prev){
            ans =min(ans ,  abs(prev -> val - root -> val));
        }
        prev = root;
        ans = min(ans , getDiff(root -> right, prev));
        
        return ans;
    }
    int getMinimumDifference(TreeNode* root) {
        TreeNode * prev = NULL;
        return getDiff(root , prev);
    }
};