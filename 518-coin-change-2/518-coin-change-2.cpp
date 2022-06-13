class Solution {
public:
    
    int dp[301][5001];
    int recur(int amount ,int n ,  vector<int>&coins){
        if(n==-1)return amount==0;
        if(amount<0)return 0;
        if(amount==0)return 1;
        if(dp[n][amount]!=-1)return dp[n][amount];
        
        int ans = recur(amount-coins[n],n,coins)+recur(amount,n-1,coins);
        
        return dp[n][amount]=ans;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return recur(amount,coins.size()-1,coins);
    }
};