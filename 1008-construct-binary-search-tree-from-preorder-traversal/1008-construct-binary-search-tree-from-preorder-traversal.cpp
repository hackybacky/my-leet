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
    TreeNode * construct(int left , int right , vector<int>&pre ){
        if(left > right){
            return NULL;
            
        }
        TreeNode * root = new TreeNode(pre[left]);
        int cur = left + 1;
        while(cur <= right and pre[cur] < pre[left])
            cur++;
        root -> left = construct(left + 1 , cur - 1 , pre);
        root -> right = construct(cur , right , pre);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return construct(0 , preorder.size() - 1, preorder);
    }
};