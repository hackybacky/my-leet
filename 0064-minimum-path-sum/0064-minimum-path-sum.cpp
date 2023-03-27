class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        function<int(int,int)> recur=[&](int i,int j){
          if(i==n-1 and j==m-1)return 0;
            
          if(dp[i][j]!=-1)return dp[i][j];
            int ans1=1e9,ans2=1e9;
           if(i+1< n )ans1=grid[i+1][j]+ recur(i+1,j);
            if(j+1< m )ans2=grid[i][j+1]+recur(i,j+1);
            return dp[i][j]=min(ans1,ans2);
        };
        return recur(0,0)+grid[0][0];
    }
};