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
    map<int , int > index;
    TreeNode * build(int &i , int left , int right , vector<int>&preorder , vector<int>&inorder){
        if(i == preorder.size() or left > right)return NULL;
        TreeNode * current = new TreeNode(preorder[i]);
        int nright = index[preorder[i]];
        i++;
        current -> left = build(i  , left , nright - 1 , preorder , inorder );
        current -> right = build(i , nright + 1 , right , preorder , inorder);
        return current;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0 ; i < n ; i++){
            index[inorder[i]] = i;
        }
        int i = 0;
        return build(i , 0 , n - 1 , preorder , inorder);
    }
};