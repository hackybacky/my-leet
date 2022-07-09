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
    TreeNode * give_my_tree(vector<int>&a , int left , int right){
        if(left>right)return NULL;
        
        TreeNode * root = new TreeNode(a[left]);
        int cur=left+1;
        while(cur<=right and a[cur]<a[left])cur++;
        
        root->left = give_my_tree(a , left+1 , cur-1);
        root->right = give_my_tree(a, cur, right);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int left=0,right=preorder.size()-1;
        return give_my_tree(preorder,left , right);
    }
};