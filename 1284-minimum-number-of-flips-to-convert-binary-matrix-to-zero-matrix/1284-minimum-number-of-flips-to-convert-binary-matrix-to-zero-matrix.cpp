class Solution {
public:
    int n, m;
    vector<vector<int>>& flip(vector<vector<int>>& mat, int y, int x) {
        mat[y][x] ^= 1;
        if(y - 1 >= 0) mat[y-1][x] ^= 1;
        if(y + 1 <  n) mat[y+1][x] ^= 1;
        if(x - 1 >= 0) mat[y][x-1] ^= 1;
        if(x + 1 <  m) mat[y][x+1] ^= 1;
        return mat;
    }

    bool isZeroMat(vector<vector<int>>& mat) {
        for(auto i = 0; i < n; ++i)
            for(auto j = 0; j < m; ++j)
                if(mat[i][j])
                    return false;
        return true;
    }
    
    int flip (int row, int col , vector<vector<int>>mat){
        if( col==m)row++,col=0;
        if(row==n){
            if(! isZeroMat(mat))return 1e6;
            else return 0;
        }
        
        return min( flip(row , col+1,mat),1+flip( row , col+1, flip(mat,row,col)));
    }
    
    int minFlips(vector<vector<int>>& mat) {
        
        
        n = mat.size();
        m = mat[0].size();
        
        int ans = flip(0,0,mat);
        if(ans>=1e6)return -1;
        return ans;
        
    }
};