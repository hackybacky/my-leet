class Solution {
public:
    vector<vector<int>> lans;
    int n;
    void solve(vector<int> nums , vector<int > ans ,vector<bool> visited){
        
        if(ans.size()==n){
            lans.push_back(ans);
            return;
        }
        
        for(int i=0 ; i< n ; i++){
            if(!visited[i]){
                int j=i;
                ans.push_back(nums[j]);
                visited[j]=true;
                while(i< n and nums[i]==nums[j])i++;
                solve(nums,ans,visited);
                
                i--;
                visited[j]=false;
                
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         n=nums.size();
        vector<bool> visited(n,false);
        solve(nums,{},visited);
        return lans;
    }
};