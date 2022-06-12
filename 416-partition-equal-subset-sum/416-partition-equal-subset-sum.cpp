class Solution {
public:
    int dp[20001];
    int recur(int su , int i ,int cur ,vector<int>&nums){
        if(i==nums.size()){
            
            return su*2==cur;
        }
        
        if(dp[su]!=-1)return dp[su];
        
        cur+=nums[i];
        su+=nums[i];
        int ans = recur(su,i+1,cur,nums);
        su-=nums[i];
        ans|=recur(su,i+1,cur,nums);
        return dp[su]=ans;
    }
    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return recur(0,0,0,nums);
    }
};