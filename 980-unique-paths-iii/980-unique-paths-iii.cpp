class Solution {
public:
    vector<vector<bool>> visited;

    int n,m,endx,endy;
    vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};
    int solve(int i,int j ,vector<vector<int>>& grid,int rem){
      
        if(i>=n or j>=m or j<0 or i<0 or grid[i][j]==-1)return 0;
        if(grid[i][j]==2){
            cout<<rem<<endl;
            return rem==0;
        }
        
        grid[i][j]=-1;
        int ans=0;
        for(int k=0 ; k<4 ; k++){
            ans+=solve(x[k]+i,j+y[k],grid,rem-1);
        }
        grid[i][j]=0;
        
        return ans;
        
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
         n=grid.size();
         m=grid[0].size();
        int rem=1;
        int startx,starty;
        for(int i=0 ; i< n ; i++){
            for(int j=0 ; j< m ; j++){
                if(grid[i][j]==1)startx=i,starty=j;
                
                else if(grid[i][j]==0)rem++;
            }
        }
        return solve(startx,starty,grid,rem);
        
     
    }
};