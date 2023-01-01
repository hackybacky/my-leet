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
    void inorder(TreeNode * root , TreeNode * & prv){
        if(!root){
            return ;
        }
        inorder(root -> left , prv);
        if(prv and prv -> val > root -> val){
            if(first == NULL){
                cout << "hello" << endl;
                first = prv , second = root;
            }
            else{
                third = root;
            }
        }
        prv = root;
        inorder(root -> right , prv);
    }
    void recoverTree(TreeNode* root) {
        TreeNode * prv = NULL;
        first = NULL , second = NULL , third = NULL;
        inorder(root , prv);
        if(third == NULL){
            // cout << "here my boio";
            swap(first -> val , second -> val);
        }
        else {
            cout << first -> val << third ->val << endl;
            swap(first -> val , third -> val);
        }
    }
};