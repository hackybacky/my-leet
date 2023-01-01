class Solution {
public:
    bool check(vector<vector<char>> &board , int col , int row , char val){
        
        //
        for(int i = 0 ; i < 9 ; i++){
            if(board[i][col] == val or board[row][i] == val)return false;
        }
        int startrow = row / 3 * 3;
        int startcol = col / 3 * 3;
        for(int i = startrow ; i < startrow + 3 ; i++){
            for(int j = startcol ; j < startcol + 3 ; j++){
                if(board[i][j] == val )return false;
            }
        }
        return true;
            
    }
   
    bool solve(vector<vector<char>> &board ){
        
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ;j < 9 ;j++){
                if(board[i][j] != '.')continue;
                for(char k = '1'  ; k <= '9' ; k++){
                    if(check(board , j , i , k)){
                        board[i][j] = k;
                        if(solve(board ))return true;
                        else
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};