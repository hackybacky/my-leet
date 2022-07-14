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
    unordered_map<int,int>indi;
    TreeNode * recur( int p , int start , int end , vector<int>&pre , vector<int>&in ){
        
        if(start>end or p==pre.size()){
            return nullptr;
        }
        TreeNode * root = new TreeNode (pre[p]);
        int ind=indi[pre[p]];
        // for(int j=start ; j<=end; j++){
        //     if(pre[p]==in[j]){
        //         ind=j;
        //         break;
        //     }
        // }
         root->right=recur(p+ind+1-start,ind+1,end,pre,in );
        root->left= recur(p+1,start,ind-1,pre,in);
       
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0; i<inorder.size(); i++)indi[inorder[i]]=i;
        return recur(0,0,preorder.size(),preorder,inorder);
        
    }
};