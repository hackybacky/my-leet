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
    int ans = 0;
    void give_ans(TreeNode * root , unordered_set<int>s){
        if(!root)return;
        auto it = s.find(root -> val);
        if( it != s.end())
            s.erase( it );
        else s.insert(root -> val);
        if(root and !(root ->left) and !(root -> right)){
            if(s.size() <= 1)ans++;
            // cout << cnt;
            return;
        }
        give_ans(root -> left , s);
        give_ans(root -> right , s);
        // return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int > mp;
         give_ans(root , mp);
        return ans;
    }
};