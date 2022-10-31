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
        
        if(!root){
            return root;
        }
        int root_val = root -> val;
        if(root_val < key){
            root -> right = deleteNode(root -> right , key);
        }
        else if(root_val > key){
            root -> left = deleteNode(root -> left , key);
        }
        else{
            if(!root -> left and !root -> right){
                return NULL;
            }
            if(!root -> left or !root -> right){
                return root -> left ? root -> left : root -> right;
            }
            auto node = root -> left;
            while(node -> right ){
                node = node -> right;
            }
            root -> val = node -> val;
            root -> left = deleteNode(root -> left , node -> val);
        }
        return root;
    }
};