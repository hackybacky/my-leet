class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int recur(int  i  , int time ,vector<int>&a){
        if(i==n)return 0;
        
        if(dp[i][time]!=-1)return dp[i][time];
        
        int ans = max( time*a[i] + recur(i+1,time+1,a) , recur(i+1,time,a)  );
        
        return dp[i][time]=ans;
    }
    int maxSatisfaction(vector<int>& a) {
        
        sort(a.begin(),a.end());
        n = a.size();
        dp.resize(n+1,vector<int>(n+2,-1));
        return recur(0,1,a);
    }
};