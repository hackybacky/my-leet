class Solution {
public:
    vector<vector<int>>visited;
    int n ,m;
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    bool check(int i,int j){
        if(i<0 or j<0 or i>=n or j>=m)return false;
        return true;
    }
    void dfs(int i, int j ,vector<vector<int>>&heights ){
        if(i<0 or j<0 or i>=n or j>=m)return;
        
        if(visited[i][j] )return ;
        
        visited[i][j]=1;
        for(int k=0;k<4; k++){
            int nx = i+x[k];
            int ny = j+y[k];
            if(check(nx,ny) and heights[nx][ny]>=heights[i][j])
            dfs(nx,ny,heights);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n  = heights.size();
        m = heights[0].size();
        visited.assign(n,vector<int>(m,0));
        for(int i=0;i<n;i++)dfs(i,m-1,heights);
        for(int i=0;i<m;i++)dfs(n-1,i,heights);
        auto p=visited;
        visited.assign(n,vector<int>(m,0));
        for(int i=0; i<n; i++)dfs(i,0,heights);
        for(int i=0; i<m;i++)dfs(0,i,heights);
        vector<vector<int>>ans;
        for(int i=0 ; i<n;i++){
            for(int j=0 ; j< m; j++){
                if(visited[i][j]&p[i][j])ans.push_back({i,j});
            }
        }
        return ans;
    }
};