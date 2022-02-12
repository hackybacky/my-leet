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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode* > q;
        map<int,vector<int>> ans;
        unordered_map<TreeNode* ,int> level;
        vector<vector<int>>lans;
        lans.push_back({root->val});
        q.push(root);
        
        while(!q.empty()){
            auto f =q.front();
            q.pop();
            if(f->left)
                level[f->left]=level[f]+1,q.push(f->left),
                ans[level[f->left]].push_back(f->left->val);
            if(f->right)
                level[f->right]=level[f]+1,q.push(f->right),
            
                ans[level[f->right]].push_back(f->right->val);
        }
        for(auto it : ans){
            vector<int>l;
            for(auto it2 : it.second){
                l.push_back(it2);
            }
            lans.push_back(l);
        }
        
        return lans;
    }
};