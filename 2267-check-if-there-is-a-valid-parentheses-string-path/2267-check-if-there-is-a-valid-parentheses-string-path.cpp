class Solution {
public:
    int n,m;
    int dp[101][101][201];
    bool recur(vector<vector<char>>&grid , int row , int col ,int bal ){
        if(row>=n or col>=m or col<0 or row<0)return 0;
        
        if(grid[row][col]=='(')bal++;
        else bal--;
        
        if(bal<0)return 0;
        
        if(row==n-1 and col==m-1){
            return bal==0;
        }
        
        if(dp[row][col][bal]!=-1)return dp[row][col][bal];
        
        int ans = recur(grid, row +1,col,bal) | recur(grid,row,col+1,bal);
        
        return dp[row][col][bal]=ans;
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        memset(dp,-1,sizeof(dp));
        m = grid[0].size();
        return recur(grid,0,0,0);
    }
};