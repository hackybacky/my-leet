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
            cout << root -> val << " "<<dis<< endl;
        }
        
        return dis;
    }
    vector<int>ans;
    int K ;
    void dfs2(TreeNode * root , int dis){
        if(!root){
            return ;
        }
        if(mp.find(root) != mp.end()){
            dis =K - mp[root];
        }
        if(dis == 0 ){
            ans.push_back(root -> val);
        }
        dfs2(root -> left , dis - 1);
        dfs2(root -> right , dis - 1);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root , target);
        K = k;
        dfs2(root , -1);
        return ans;
        
    }
};