class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
        function<int(int,int)> recur=[&](int i,int j){
          if(i==n-1 and j==m-1){
              if(a[i][j]==0)return 1;
              else return 0;
          }
            if(dp[i][j]!=-1)return dp[i][j];
            if(a[i][j]==1){
                return dp[i][j]=0;
            }
            int ans=0;
            if(i+1<n and a[i+1][j]==0)ans+=recur(i+1,j);
            if(j+1<m and a[i][j+1]==0)ans+=recur(i,j+1);
            return dp[i][j]=ans;
        };
        return recur(0,0);
    }
};