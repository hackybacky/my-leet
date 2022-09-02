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
    vector<double> averageOfLevels(TreeNode* root) {
        
        queue<TreeNode *> q;
        
        q.push(root);
        vector<double > ans;
        while(!q.empty()){
            int n = q.size();
            double sum=0,cnt=0;
            for(int i=0 ; i<n ;  i++){
                auto f = q.front();
                q.pop();
                sum+=f->val;
                cnt++;
                if(f->left)q.push(f->left);
                if(f->right)q.push(f->right);
            }
            ans.push_back(sum/cnt);
        }
        return ans;
    }
};