class Solution {
public:
    int n;
    long long dp[101][101];
    long long  recur( int i , int f  ,vector<vector<int>>&a){
        if(i==n){
            if(f==n/2 )return 0;
            else return 1e6;
        }
        
        if(dp[i][f]!=-1)return dp[i][f];
        
        int ans ;
        
        ans = min( a[i][0]+recur(i+1,f+1,a) , a[i][1]+recur(i+1,f,a) );
        
        return dp[i][f]=ans;
        
        
    }
    
    int twoCitySchedCost(vector<vector<int>>& a) {
        n=a.size();
        memset(dp,-1,sizeof(dp));
        long long ans = recur(0,0,a);
        return ans;
    }
};