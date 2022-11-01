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
   TreeNode * first , * second , * third;
    
    void inorder(TreeNode * root , TreeNode * & prev){
        if(!root){
            return ;
        }
        inorder(root -> left , prev);
        if(prev and prev -> val > root -> val){
            if(first == NULL){
                first = prev , second = root;
            }
            else third = root;
        }
        prev = root;
        inorder(root -> right , prev);
    }
   void recoverTree(TreeNode* root) {
       TreeNode * prev = NULL;
       inorder(root , prev);
       if(first and third){
           swap(first -> val , third -> val);
           
       }
       else if(first ){
           swap(first -> val , second -> val);
       }
    }
};