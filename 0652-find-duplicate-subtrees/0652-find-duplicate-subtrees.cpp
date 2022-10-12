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
    unordered_map<string , int > mp;
    vector<TreeNode *> ans ;
    string dfs(TreeNode * root ){
        if(!root){
            return "$";
        }
        
        string cur = "";
        string l = dfs(root -> left);
        string r = dfs(root -> right);
        
        cur += to_string(root -> val );
        cur +="$"+ l + "$" + r;
        if(mp.find(cur) != mp.end() and mp[cur] == 1 ){
            cout << cur << endl;
            ans.push_back(root);
        }
        mp[cur] += 1;
        return cur;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // ans = 0;
        dfs(root);
        return ans;
        
    }
};