class Solution {
public:
    int ans ;
    vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};
    int n ,m;
    void dfs(int curx , int cury , vector<vector<int>>&grid){
        if(curx<0 or cury<0 or cury>=m or curx>=n or grid[curx][cury]==0)return ;
        grid[curx][cury]=0;
        ans++;
        for(int i=0;i<4;i++){
            int nx = curx+x[i];
            int ny = cury+y[i];
            dfs(nx,ny,grid);
        }
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int lans=0;
        for(int i=0;i<n ;i++){
            for(int j=0;j<m; j++){
                if(grid[i][j]==1){
                    
                    ans=0;
                    dfs(i,j,grid);
                    lans = max(ans,lans);
                    // cout<<ans<<endl;
                }
            }
        }
        return lans;
    }
};