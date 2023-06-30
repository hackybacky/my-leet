class Solution {
public:
    vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};
    int dfs(int i , int j , vector<vector<int>>&grid){
        if(i < 0  or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] != 1)return 0;
        grid[i][j] = 2;
        int ans = 1;
        for(int k = 0; k < 4 ;k++){
            int nx = x[k] + i;
            int ny = y[k] + j;
            ans += dfs(nx , ny , grid);
        }
        return ans;
    }
    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        
        
        for(auto it : hits){
            grid[it[0]][it[1]]--;
        }
      
        int ans = 0 ;
        for(int i = 0 ; i < grid[0].size();i++) dfs(0 , i , grid);
        int n = hits.size();
        vector<int>res;
        for(int i = n - 1 ; i >= 0 ; i--){
            int u = hits[i][0];
            int v = hits[i][1];
            bool flag = false;
            grid[u][v]++;
            for(int k = 0 ; k < 4 ; k++){
                int nx = u + x[k];
                int ny = v + y[k];
                if(nx >=0 and nx < grid.size() and ny < grid[0].size() and ny >=0 and grid[nx][ny] == 2  )flag = true;
            }
            if(grid[u][v] == 1 and (u == 0 or flag) ){
                ans = dfs(u , v , grid);
                res.push_back(ans - 1);
            }
            else res.push_back(0);
        }
        reverse(res.begin() , res.end());
        return res;
    }
};