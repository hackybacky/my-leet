class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        
        while(k--){
            auto c = grid;
            for(int i=0; i<grid.size(); i++){
                for(int j=0 ; j<grid[0].size(); j++){
                    int back=(j==0)?grid[0].size()-1:j-1;
                    grid[i][j]=c[i][back];
                    
                }
            }
            int last  = grid[grid.size()-1][0];
            for(int i=grid.size()-1; i>=1; i--){
            
                grid[i][0]=grid[i-1][0];
            }
            grid[0][0]=last;
            
        }
        
        return grid;
    }
};