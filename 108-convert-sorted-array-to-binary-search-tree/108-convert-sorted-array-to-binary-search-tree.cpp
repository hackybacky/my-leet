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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int sz = nums.size();
        if(sz==0)return NULL;
        
        int ele = nums[sz/2];
        
        TreeNode * root = new TreeNode(ele);
        auto a=vector(nums.begin(),nums.begin()+sz/2);
        root->left = sortedArrayToBST( a );
        auto b = vector(nums.begin()+sz/2+1,nums.end());
        root->right = sortedArrayToBST(b);
        return root;
    }
};