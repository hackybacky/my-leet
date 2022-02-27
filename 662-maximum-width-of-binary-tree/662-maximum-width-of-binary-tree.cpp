class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        //int ans=0;
        
        queue<pair<TreeNode * , int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            queue<pair<TreeNode * , int>> t;
            int mn=INT_MAX,mx=INT_MIN;
            int s=q.size();
            for(int i=0; i<s; i++){
                auto it = q.front();
                auto node = it.first;
                auto indi = it.second;
                q.pop();
                mn=min(mn,indi);
                mx=max(mx,indi);
                if(node->left!=NULL)q.push({node->left,(long long)2*indi+1});
                if(node->right!=NULL)q.push({node->right,(long long)2*indi+2});
                
            }
            
            ans=max(ans,mx-mn+1);
        }
        return ans;
    }
};