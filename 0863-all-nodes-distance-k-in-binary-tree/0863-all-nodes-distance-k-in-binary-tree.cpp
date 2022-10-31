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
    map<TreeNode * , int > mp;
    int dfs(TreeNode * root , TreeNode * target){
        if(!root){
            return -1;
        }
        
        if(root == target){
            mp[target] = 0;
            return 0;
        }
        
        int l = dfs(root -> left , target) ;
        int r = dfs(root -> right , target);
        int dis = -1;
        if(l >= 0 ){
            dis = l + 1;
        }
        if(r >= 0){
            dis = r + 1;
        }
        if(dis > 0){
            mp[root] = dis;
        }
        
        return dis;
    }
    // vector<int>ans;
    int K ;
    vector<int> dfs2(TreeNode * root , int dis){
        vector<int>ans;
        if(!root){
            return ans;
        }
        if(mp.find(root) != mp.end()){
            dis =K - mp[root];
        }
        if(dis == 0 ){
            ans.push_back(root -> val);
        }
        vector<int> a = dfs2(root -> left , dis - 1);
        vector<int> b = dfs2(root -> right , dis - 1);
        for(auto it : a){
            ans.push_back(it);
        }
        for(auto it : b){
            ans.push_back(it);
        }
        return ans;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root , target);
        K = k;
        return dfs2(root , -1);
        // return ans;
        
    }
};