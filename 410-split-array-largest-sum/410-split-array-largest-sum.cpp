class Solution {
public:
    int dp[1001][51];
    int M;
    int recur(int l,int take,vector<int>&nums){
        if(l>=nums.size()){
            if(take==M)return 0;
            else return INT_MAX;
        }
        
        if(take>=M)return INT_MAX;
        
        if(dp[l][take]!=-1)return dp[l][take];
        int cur=0;
        int ans = INT_MAX;
        for(int i=l;i<nums.size();i++){
            cur+=nums[i];
            ans = min(ans,max(cur,recur(i+1,take+1,nums)));
        }
        return dp[l][take]=ans;
        
    }
    int splitArray(vector<int>& nums, int m) {
        memset(dp,-1,sizeof(dp));
        M=m;
        return recur(0,0,nums);
    }
};