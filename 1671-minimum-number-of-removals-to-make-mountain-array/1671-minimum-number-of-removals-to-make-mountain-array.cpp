class Solution {
public:
    int dp[1001][1001][2][2];
    int recur(int i , int prev,vector<int>&nums,bool flag,bool take){
        if(i==nums.size()){
            if(take)return 0;
            return 1e6;
        }
        if(dp[i][prev][flag][take]!=-1)return dp[i][prev][flag][take];
        int ans=INT_MAX;
        
        ans=1+recur(i+1,prev,nums,flag,take);
        if(flag){
            if(nums[i]<nums[prev])ans=min(ans,recur(i+1,i,nums,flag,true));
        }
        else{
            if(nums[i]>nums[prev])ans=min({ans,recur(i+1,i,nums,flag,take),recur(i+1,i,nums,true,take)});
        }
        return dp[i][prev][flag][take]=ans;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            // cout<<max(0,i-1)<<" "<<recur(i+1,i,nums,false)<<endl;
            ans=min(ans,i+recur(i+1,i,nums,false,false));
        }
        return ans;
    }
};