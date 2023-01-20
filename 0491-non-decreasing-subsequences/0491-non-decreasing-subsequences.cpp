class Solution {
public:
    vector<vector<int>>fans;
    void dfs(int i , vector<int>&ans , vector<int>&nums){
        
        if(ans.size() >=2 )
        fans.push_back(ans);
        map<int , int> mp;
        for(int k = i ; k < nums.size() ; k++){
            if(mp.find(nums[k]) == mp.end() and (ans.empty() or ans.back() <= nums[k])){
                ans.push_back(nums[k]);
                dfs(k + 1  , ans , nums );
                ans.pop_back();
                mp[nums[k]] = 1;
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int>ans;
        dfs(0 , ans , nums);
        return fans;
    }
};