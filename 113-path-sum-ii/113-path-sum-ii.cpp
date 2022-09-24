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
    vector<vector<int>>lans;
    void recur(vector<int>&cur , TreeNode *root , int current_sum , int targetSum){
        if(!root)return;
        if(root -> left == nullptr and root -> right == nullptr){
            current_sum += root -> val;
            cur.push_back(root -> val);
            if(current_sum == targetSum)
                lans.push_back(cur);
            cur.pop_back();
            return;
        }
        cur.push_back(root -> val);
        recur(cur , root ->left , current_sum + root -> val , targetSum);
        
        recur(cur , root -> right , current_sum + root -> val , targetSum );
        cur.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>cur;
        recur(cur , root , 0 , targetSum);
        return lans;
    }
};