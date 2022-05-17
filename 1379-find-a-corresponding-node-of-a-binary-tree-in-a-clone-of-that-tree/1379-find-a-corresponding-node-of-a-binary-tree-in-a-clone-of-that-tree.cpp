/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode *ans;
    void recur(TreeNode* original , TreeNode *cloned,TreeNode *target){
        if(original==NULL)return ;
        
        if(original == target){ans=cloned;return;}
        
    getTargetCopy(original->left,cloned->left,target);getTargetCopy(original->right,cloned->right,target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        recur(original , cloned ,target);
        return ans;
    }
};