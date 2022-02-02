class Solution {
public:
    int dp[1001][201][2];
    int n;
    int recur(int i,int k,bool check,vector<int>prices){
        if(i==n)return 0;
        if(k==0)return 0;
        
        if(dp[i][k][check]!=-1)return dp[i][k][check];
        int ans;
        if(check){
            ans=max(prices[i]+recur(i+1,k-1,0,prices),recur(i+1,k,1,prices));
            
        }else{
            ans=max(-prices[i]+recur(i+1,k-1,1,prices),recur(i+1,k,check,prices));
            
        }
        return dp[i][k][check]=ans;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
       
        memset(dp,-1,sizeof(dp));
        return recur(0,2*k,0,prices);
    }
};