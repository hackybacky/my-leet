class Solution {
public:
  map<int,int> dp;
    int N;
    
        
    int recur(int  n){
        
        
        if(dp.find(n)!=dp.end())return dp[n];
        
        int ans=INT_MAX;
        if(n%3==0){
            ans=min(ans,recur(n/3)+1);
        }
        if(n%2==0){
            ans=min(ans,recur(n/2)+1);
        }
        if(n%2!=0 or  n%3!=0)ans=min(ans,1+recur(n-1));
        
        return dp[n]=ans;
        
        
        
    }
    int minDays(int n) {
       
        dp[0]=0;
        dp[1]=1;
        return recur(n);
    }
};