class Solution {
public:
    int N,K;
    int dp[100001][5];
    
    int recur(int  i,int k ,vector<int>&prices){
        if(k==0)return 0;
        if(i==N)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        
        bool buy= k%2==0;
        int ans;
        if(buy){
            ans=max(-prices[i]+recur(i+1,k-1,prices),recur(i+1,k,prices));
        }
        else{
            ans=max(prices[i]+recur(i+1,k-1,prices),recur(i+1,k,prices));
        }
        
        return dp[i][k]=ans;
        
    }
    
    int maxProfit(vector<int>& prices) {
        N=prices.size();
        memset(dp,-1,sizeof(dp));
        return recur(0,4,prices);
    }
};