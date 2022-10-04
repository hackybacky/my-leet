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
    bool recur(TreeNode * root , int sum){
        if(!root){
            return 0;
        }
        sum -= (root -> val);
        if(!root -> left and !root -> right){
            // cout << root -> val << endl;
            
            return sum == 0;
        }
        auto ans = recur(root -> left , sum  );
        ans |= recur(root -> right , sum);
        sum += root -> val;
        return ans;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        return recur(root , targetSum);   
    }
};