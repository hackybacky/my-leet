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
    bool check(TreeNode * root){
        return root!=nullptr;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q;
        
        q.push(root);
        int level=0;
        vector<vector<int>>lans;
        while(!q.empty()){
            queue<TreeNode*>t;
            vector<int>ans;
            while(!q.empty()){
                auto f = q.front();
                auto node = f;
                q.pop();
                ans.push_back(node->val);
                if(check(node->left))t.push(node->left);
                if(check(node->right))t.push(node->right);
            }
            if(level%2==1)reverse(ans.begin(),ans.end());
            lans.push_back(ans);
            level++;
            q=t;
        }
        return lans;
    }
};