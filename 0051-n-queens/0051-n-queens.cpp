class Solution {
public:
    int n;
    bool place(int i, int j , vector<string>board ){
        
        int row = i , col = j;
        while(row>=0){
            if(board[row][col]=='Q'){return false;}
            row--;
        }
        row = i , col = j;
        while(row>=0 and col>=0){
            if(board[row][col]=='Q')return false;
            row--,col--;
        }
        row = i , col= j;
        while(row>=0 and col<n){
            if(board[row][col]=='Q')return false;
            row--,col++;
        }
        return true;
    }
    vector<vector<string>>ans;
    bool check(int i , vector<string>&board){
        if(i==n)return true;
        for(int j=0 ;  j<n ; j++ ){
            
            if(place(i,j,board)){
                board[i][j]='Q';
                if(check(i+1,board)){
                    ans.push_back(board);
                }
                board[i][j]='.';
            }
        }
        return false;
        
    }
    vector<vector<string>> solveNQueens(int N) {
        vector<string> board(N,string(N,'.'));
        n=N;
                                     
        check(0,board);
        return ans;
        
    }
}
;