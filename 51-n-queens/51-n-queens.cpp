class Solution {
public:
    int N;
    bool check(vector<string > board,int row,int col){
        int i, j;

        /* Check this row on left side */
        for (i = 0; i < col; i++)
            if (board[row][i]=='Q')
                return false;

        /* Check upper diagonal on left side */
        for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j]=='Q')
                return false;

        /* Check lower diagonal on left side */
        for (i = row, j = col; j >= 0 && i < N; i++, j--)
            if (board[i][j]=='Q')
                return false;
        return true;
    }
    
    vector<vector<string>> lans;
    bool solve(vector<string> board, int col  ){
        
        if(col>=N){return true;}
        
        for(int i=0 ; i< N ; i++){
            
            if(check(board,i,col)){
                board[i][col]='Q';
                if(solve(board,col+1)){
                    lans.push_back(board);
                }
                
                board[i][col]='.';

            }
            
        }
        return false;
        
    }
    vector<vector<string>> solveNQueens(int n) {
        N=n;
        vector<string> board(n,string(n,'.'));
        
        
        solve(board,0);
        return lans;
    }
};