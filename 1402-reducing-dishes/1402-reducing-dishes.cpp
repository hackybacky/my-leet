class Solution {
public:
    int dp[501][502];
    int n;
    int recur(int  i  , int time ,vector<int>&a){
        if(i==n)return 0;
        
        if(dp[i][time]!=-1)return dp[i][time];
        
        int ans = max( time*a[i] + recur(i+1,time+1,a) , recur(i+1,time,a)  );
        
        return dp[i][time]=ans;
    }
    int maxSatisfaction(vector<int>& a) {
        memset(dp,-1,sizeof(dp));
        sort(a.begin(),a.end());
        n = a.size();
        return recur(0,1,a);
    }
};