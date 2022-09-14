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
    int ans = 0;
    void give_ans(TreeNode * root , int mask){
        if(!root)return;
        int val = root -> val;
        mask ^= (1 << val);
        if(root and !(root ->left) and !(root -> right)){
            int bit = __builtin_popcount(mask);
            if( bit <= 1)ans++;
            // cout << cnt;
            return;
        }
        give_ans(root -> left , mask);
        give_ans(root -> right , mask);
        // return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        // unordered_set<int > mp;
        
         give_ans(root , 0);
        return ans;
    }
};