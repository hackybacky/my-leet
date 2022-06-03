class NumMatrix {
public:
    vector<vector<int>>dp;
    int n ,m;
    NumMatrix(vector<vector<int>>& matrix) {
         n = matrix.size();
         m= matrix[0].size();
        dp.assign(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++){
            for(int j=0 ; j<m; j++) {
                
                dp[i][j]=matrix[i][j];
                dp[i][j]+=(i-1>=0?dp[i-1][j]:0);
                dp[i][j]+=(j-1>=0?dp[i][j-1]:0);
                dp[i][j]-=(i-1>=0 and j-1>=0 ? dp[i-1][j-1]:0);
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int ans = dp[row2][col2];
        ans += (row1-1>=0 and col1-1>=0?dp[row1-1][col1-1]:0);
        ans-=(col1-1>=0?dp[row2][col1-1]:0);
        ans-=(row1-1>=0?dp[row1-1][col2]:0);
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */