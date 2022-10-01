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
    TreeNode * smallest_value_right_subtree(TreeNode * root ){
        
        root = root -> right;
        
        
        while(root and root -> left){
            root = root -> left;
        }
        return root;
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root == NULL)
            return root;
        if(root -> left == NULL and root -> right == NULL and root -> val == key)
            return NULL;
        if(root -> val == key){
            // 
            if(root -> left == NULL)
                return root -> right;
            if(root -> right == NULL)
                return root -> left;
            TreeNode * value = smallest_value_right_subtree(root );
            root -> val = value -> val;
            root -> right = deleteNode(root -> right , value -> val);
        }
        else{
            if(root -> val < key){
                root -> right =deleteNode(root -> right , key);
            }
            else{
                root -> left = deleteNode(root -> left , key);
            }
        }
        return root;
    }
};