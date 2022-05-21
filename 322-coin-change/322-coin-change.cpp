class Solution {
public:
    int dp[10001];
    int recur(vector<int>&coins, int rm ){
    
        if(rm ==0)return 0;
        else if(rm<coins[0] or rm<0)return 1e5;
        if(dp[rm]!=-1)return dp[rm];
        int ans=INT_MAX;
        for(int j=0;j<coins.size(); j++){
            ans=min(ans,1+recur(coins,rm-coins[j]));
        }
        
        return dp[rm]=ans;
        
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        sort(coins.begin(),coins.end());
        int ans= recur(coins,amount);
        return ans >1e4?-1:ans;
    }
};