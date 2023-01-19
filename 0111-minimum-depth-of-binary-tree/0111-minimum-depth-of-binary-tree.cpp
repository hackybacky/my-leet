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
    int minDepth(TreeNode* root) {
        if(!root)return 0 ;
        int ans = INT_MAX ,  ans2 = INT_MAX;
        if(root -> left){
            ans = minDepth(root -> left);
            
        }
        if(root -> right){
            ans2 = minDepth(root -> right);
        }
        if(!root -> right and !root -> left) ans = 0;
        // cout << root -> val << " " << ans << " "<< ans2 << endl;
        return min(ans , ans2) + 1; 
    }
};