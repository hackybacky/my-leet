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
    struct Node{
        int ma=INT_MIN;
        int mi = INT_MAX;
        bool bst =true;
        int ans=0;
    };
    int last;
    Node * recur(TreeNode * root){
        if(!root)return new Node();
        
        auto left = recur(root->left);
        auto right = recur(root->right);
        auto cur=new Node();
        if(left->ma<root->val and right->mi>root->val and left->bst and right->bst){
            cur->ma = max(right->ma,root->val);
            cur->mi = min(root->val,left->mi);
            cur->bst=true;
            cur->ans=left->ans+right->ans+root->val;
            last=max(last,cur->ans);
        }
        else{
            cur->bst=false;
            
        }
        return cur;
    }
    int maxSumBST(TreeNode* root) {
        recur(root);
        return last;
    }
};