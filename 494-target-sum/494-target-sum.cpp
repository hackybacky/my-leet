class Solution {
public:
    map<pair<int,int>,int>dp;
    int recur(int i, int sum , int target, vector<int>&nums){
        if(i==nums.size()){
            return sum == target;
        }
        if(dp.find({sum,i})!=dp.end())return dp[{sum,i}];
        
        int ans = recur(i+1,sum+nums[i],target,nums)+recur(i+1,sum-nums[i],target,nums);
        
        return dp[{sum,i}]=ans;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return recur(0,0,target,nums);
    }
};