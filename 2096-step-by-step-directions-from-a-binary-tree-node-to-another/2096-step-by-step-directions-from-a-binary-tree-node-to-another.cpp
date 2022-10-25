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
    string cura , curb;
    void dfs(TreeNode * root , int a , int b , string & cur){
        if(!root){
            return ;
        }
        
        if(root -> val == a){
            cura = cur;
        }
        if(root -> val == b){
            curb = cur;
        }
        cur.push_back('L');
        dfs(root -> left , a , b , cur);
        cur.back() = 'R';
        dfs(root -> right , a , b , cur);
        cur.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string cur = "";
        dfs(root , startValue , destValue , cur);
        int n = cura.size()  , m = curb.size();
        int i = 0 , j = 0;
        while(i < n and j < m and cura[i] == curb[j])i++ , j++;
        
        string ans = "";
        while(i < n){
            ans += "U";
            i++;
        }
        while(j < m){
            ans += curb[j++];
        }

        return ans ;
    }
};