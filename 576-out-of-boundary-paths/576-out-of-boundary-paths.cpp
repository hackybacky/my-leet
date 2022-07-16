class Solution {
public:
    int dp[51][51][51];
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    const int mod =1e9+7;
    int dfs(int m,int n , int maxMove ,int curx , int cury){
        
        if(curx<0 or cury<0 or curx>=m or cury>=n)return 1;
        if(dp[curx][cury][maxMove]!=-1)return dp[curx][cury][maxMove];
        
        if(maxMove==0)return dp[curx][cury][maxMove]=0;
    
        int ans=0;
        for(int i=0;i<4 ; i++){
            int nx = curx+x[i];
            int ny = cury + y[i];
            ans = (ans+dfs(m,n,maxMove-1, nx,ny))%mod;
        }
        return dp[curx][cury][maxMove]= ans%mod;
        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return dfs(m,n,maxMove, startRow , startColumn);
        
    }
};