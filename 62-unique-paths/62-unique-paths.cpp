class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        
        function <int (int,int)> recur=[&](int i,int j ){
            if(i==m-1 and j==n-1)return 1;
            if(dp[i][j]!=-1)return dp[i][j];
            int ans=0;
            if(i+1<m)ans+=recur(i+1,j);
            if(j+1<n)ans+=recur(i,j+1);
            return dp[i][j]=ans;
        };
        
        return recur(0,0);
    }
};