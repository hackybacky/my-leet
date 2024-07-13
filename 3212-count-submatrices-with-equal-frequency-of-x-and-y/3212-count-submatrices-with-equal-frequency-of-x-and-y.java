class Solution {
    int giveCnt(int [][]cnt,int x, int y){
        return ( (y - 1) >=0 ? cnt[x][y - 1]:0) + ((x - 1) >=0 ?cnt[x-1][y] : 0) + cnt[x][y] - ((x - 1 >=0  && y - 1>=0)?cnt[x-1][y-1]:0 );
    }
    
    void updateCnt(int [][]cntx,int [][]cnty, int x , int y ,char[][]grid){
        char c = grid[x][y];
        cntx[x][y] = 0;
        cnty[x][y] = 0;
        if(c == 'X')cntx[x][y] = 1; cntx[x][y] = giveCnt(cntx,x,y);
        if(c == 'Y')cnty[x][y] = 1; cnty[x][y] = giveCnt(cnty,x,y);
    }
    public int numberOfSubmatrices(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int ans = 0;
        int [][] cntx = new int[n][m];
        int [][] cnty = new int [n][m];
        for(int i = 0  ; i < n; i++){
            for(int j = 0 ; j < m;j++){
                updateCnt(cntx,cnty,i,j,grid);
                if(cntx[i][j] == cnty[i][j] && cntx[i][j]!=0){
                    System.out.println(cntx[i][j]);
                    ans++;
                }
                
            }
        }
        return ans;
    }
}