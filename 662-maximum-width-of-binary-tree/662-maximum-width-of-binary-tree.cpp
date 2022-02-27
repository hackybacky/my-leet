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
    int widthOfBinaryTree(TreeNode* root) {
        //int ans=0;
        
        queue<pair<TreeNode * , int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            queue<pair<TreeNode * , int>> t;
            int mn=INT_MAX,mx=INT_MIN;
            while(!q.empty()){
                auto it = q.front();
                auto node = it.first;
                auto indi = it.second;
                q.pop();
                mn=min(mn,indi);
                mx=max(mx,indi);
                if(node->left)t.push({node->left,(long long)2*indi+1});
                if(node->right)t.push({node->right,(long long)2*indi+2});
                
            }
            q=t;
            ans=max(ans,mx-mn+1);
        }
        return ans;
    }
};