class Solution {
public:
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    vector<vector<int>>visited;
    int n,m;
    void dfs(int i, int j , vector<vector<char>>&grid){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]=='0')return;
        if(visited[i][j]==1)return;
        visited[i][j]=1;
        for(int k=0;k<4; k++){
            int nx = i+x[k];
            int ny = j+y[k];  
            dfs(nx,ny,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
         n = grid.size();
        m = grid[0].size();
        visited.assign(n,vector<int>(m,0));
        int ans=0;
        for(int i=0  ; i<n ; i++){
            for(int j=0; j<m; j++){
                
                if(!visited[i][j] and grid[i][j]=='1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};