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
    TreeNode * recur(int& pos , int start , int end , vector<int>&post, vector<int>&in){
        if(pos<0 or start>end){
            return nullptr;
        }
        cout<<post[pos]<<endl;
        TreeNode * root = new TreeNode (post[pos]);
        int ind = indi[post[pos]];
       pos--;
        root->right = recur(pos,ind+1,end,post,in);
        root->left = recur(pos,start,ind-1,post,in);
        
        return root;
        
        
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for(int i=0 ; i<n; i++)indi[inorder[i]]=i;
        int po=n-1;
        return recur(po,0,n-1,postorder,inorder);
    }
};