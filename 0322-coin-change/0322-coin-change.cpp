class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        int n = coins.size();
        
        for(int i=1;i<=amount;i++){
            
            for(int j=0;j <n; j++){
                int cur = i;
                int take = cur-coins[j];
                // cout<<take<<endl;
                if(take>=0 and dp[take]!=INT_MAX)dp[i]=min(dp[i],1+dp[take]);
            }
        }
        if(dp[amount]==INT_MAX)return -1;return dp[amount];
    }
};