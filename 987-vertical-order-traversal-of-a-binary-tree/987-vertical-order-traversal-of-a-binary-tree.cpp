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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode * ,pair<int, int>>> q;
        
        map<pair<int,int>,vector<int>>mp;
        
        q.push({root,{0,0}});
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            auto node = f.first;
            auto line= f.second.first;
            auto level = f.second.second;
            mp[{line,level}].push_back(node->val);
            if(node->left)q.push({node->left,{line-1,level+1}});
            if(node->right)q.push({node->right,{line+1,level+1}});
        }
        vector<vector<int>>ans;
        map<int,vector<int>>indi;
        for(auto &it : mp){
            sort(it.second.begin(),it.second.end());
            for(auto it2 : it.second)
            indi[it.first.first].push_back(it2);
        }
        for(auto it : indi)ans.push_back(it.second);
        return ans;
    }
};