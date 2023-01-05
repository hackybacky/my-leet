class Solution {
public:
    int dp[5001][2];
    int recur(int i , int par,vector<int>&prices){
        if(i>=prices.size()){
            if(par==1)return INT_MIN/2;
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
        memset(dp,-1,sizeof(dp));
        return recur(0 , 0 , prices);
    }
};