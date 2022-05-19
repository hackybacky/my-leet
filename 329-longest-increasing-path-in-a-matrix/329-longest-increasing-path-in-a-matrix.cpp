class Solution {
public:
vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};
    int n ,m;
    int dp[201][201];
    int dfs(int i , int j , vector<vector<int>>&mat){
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k=0;k < 4; k++){
            int nx = x[k]+i;
            int ny = y[k]+j;
            
            if((nx==i and ny == j) or nx<0 or ny<0 or nx>=n or ny>=m)continue;
            if(mat[i][j]<mat[nx][ny]){
                ans=max(ans,1+dfs(nx,ny,mat));
            }
            // else dfs(nx,ny,mat);
            
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {        
        memset(dp,-1,sizeof(dp));
        n=matrix.size();
        m = matrix[0].size();
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                ans=max(ans,dfs(i,j,matrix));
            }
        }
        return ans+1;
    }
};