class Solution {
public:
    int dp[5001][2];
    int recur(int i , int par,vector<int>&prices){
        if(i>=prices.size()){
            return 0;
        }
        
        if(dp[i][par]!=-1)return dp[i][par];
        int ans=0;
        int ans2=recur(i+1,par,prices);
        
        if(par==0){
            
            ans=-prices[i]+recur(i+1,1,prices);
        }
        else{
            ans=prices[i]+recur(i+2,0,prices);
        }
        // cout<<ans<<" "<<ans2<<" "<<i<<endl;
        return dp[i][par]=max(ans,ans2);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,0,sizeof(dp));
        int n = prices.size();
        
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int j = 0 ; j < 2 ; j++){
                dp[i][j] = dp[i + 1][j];
                int ans = 0;
                if(j == 0){
                    ans = -prices[i] + dp[i + 1][1];
                }
                else ans = prices[i] + dp[i + 2][0];
                dp[i][j] = max(ans , dp[i][j]);
            }
        }
        return dp[0][0];
    }
};