class Solution {
public:
    int N;
    bool check(vector<string > board,int row,int col){
        
        for(int k=0 ; k<col ; k++){
            if(board[row][k]=='Q')return false;
        }
        
        int i=row,j=col;
        
        while(i>=0 and j>=0 ){
            if(board[i][j]=='Q')return false;
            i--,j--;
        }
        i=row,j=col;
        while(i<N and j>=0){
            if(board[i][j]=='Q')return false;
            i++,j--;
        }
        
        return true;
    }
    
   
    void solve(vector<string> board, int col  ){
        
        if(col>=N){ans++;}
        
        for(int i=0 ; i< N ; i++){
            
            if(check(board,i,col)){
                board[i][col]='Q';
                (solve(board,col+1));
                    
                
                
                board[i][col]='.';

            }
            
        }
       // return false;
        
    }
    int ans;
    int totalNQueens(int n) {
         N=n;
        ans=0;
        vector<string> board(n,string(n,'.'));
        
        
        solve(board,0);
        return ans;
    }
};