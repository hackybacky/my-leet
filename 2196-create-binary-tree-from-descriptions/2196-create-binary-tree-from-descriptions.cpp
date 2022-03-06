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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,vector<pair<int,int>>> graph;
        unordered_map<int,int>indeg;
        vector<int>n;
        for(auto i : d)    {
           
                graph[i[0]].push_back({i[1],i[2]});
                indeg[i[1]]++;
                n.push_back(i[0])    ;
                 n .push_back(i[1]);
            
        }
        int root =0;
        for(auto it : n){
            if(indeg[it]==0)root = it;
        }
        TreeNode * r = new TreeNode();
        auto anas = r;
        r->val=root;
        function <void(TreeNode *,int )>dfs=[&](TreeNode *root,int node){
            for(auto i : graph[node]){
                
                    if(i.second==1){
                        root->left=new TreeNode();
                        root->left->val=i.first;
                        dfs(root->left,i.first);
                    }
                    else {
                        root->right=new TreeNode();
                        root->right->val=i.first;
                        dfs(root->right,i.first);
                    }
                
            }
        };
        dfs(r,root);
        return anas;
        
        
        
    }
};

