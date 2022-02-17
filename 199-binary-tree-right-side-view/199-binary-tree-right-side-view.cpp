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
    vector<int>ans;
    int sz;
    void print(TreeNode * root,int lv){
        if(!root)return;
        if(sz<=lv)sz++,ans.push_back(root->val);
        print(root->right ,lv+1);
        print(root->left,lv+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        print(root,0);
        return ans;
    }
};