class Solution {
public:
    vector<vector<int>> lans;
    int n;
    void solve(vector<int> &nums,vector<int> ans,vector<bool>& visited){
        if(ans.size()==n){
            lans.push_back(ans);
            return;
        }
        for(int i=0  ; i<n; i++){
            if(!visited[i]){
                visited[i]=true;
                ans.push_back(nums[i]);
                solve(nums,ans,visited);
                visited[i]=false;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<bool> visited(n,false);
        solve(nums,{},visited);
        return lans;
        
    }
};