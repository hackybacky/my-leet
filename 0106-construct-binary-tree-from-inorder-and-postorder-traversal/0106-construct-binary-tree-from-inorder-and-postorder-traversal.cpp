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
    TreeNode * build(int& i , int left , int right , vector<int>&in , vector<int> &post){
        if(i == -1 or left > right )return NULL;
        TreeNode * current = new TreeNode( post[i]);
        int nright = index[post[i]];
        i--;
        current -> right = build(i , nright + 1, right , in ,post);
        current -> left = build(i , left , nright - 1 , in , post);
        return current;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        for(int i = 0 ; i < n ; i++){
            index[inorder[i]] = i;
        }
        int i = n - 1;
        
        return build(i , 0 , n - 1 , inorder ,postorder);
    }
};