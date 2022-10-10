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
   void recoverTree(TreeNode* root) {
       TreeNode* curr=root,*prev=NULL,*a=NULL,*b=NULL;
      
	  while(curr!=NULL){
        if(curr->left==NULL){
          if(prev!=NULL && prev->val>curr->val){
            if(a==NULL){
              a=prev;
            }
            b=curr;
          }
          prev=curr;
		  
          curr=curr->right;
        }
        else{
          TreeNode* leftNode=curr->left;
          while(leftNode->right!=NULL && leftNode->right!=curr){
            leftNode=leftNode->right;  
          }
          if(leftNode->right==NULL){
            leftNode->right=curr;
            curr=curr->left;
          }
          else{
            leftNode->right=NULL;
			
            if(prev->val>curr->val){
             if(a==NULL){
              a=prev;
             }
             b=curr;
           }
            prev=curr;
			//Main Logic ends----------------
            curr=curr->right;
          }
        }
      }
	  
      if(a!=NULL){
        int temp=a->val;
        a->val=b->val;
        b->val=temp;
      }  
    }
};