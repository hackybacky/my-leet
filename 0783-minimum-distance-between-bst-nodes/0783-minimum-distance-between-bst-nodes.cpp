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
    int ans = INT_MAX;
    void inorder(TreeNode * root , TreeNode  * &pre){
        if(!root){
            return;
        }
        inorder(root -> left , pre);
        if(pre != nullptr){
            int c = pre -> val;
            int d = root -> val;
            ans = min(ans , d - c);
            
        }
        pre = root;
        inorder(root -> right , pre);
    }
    int minDiffInBST(TreeNode* root) {
        TreeNode * prev = new TreeNode(INT_MIN/2) ;
        inorder(root , prev );
        return ans;
    }
};