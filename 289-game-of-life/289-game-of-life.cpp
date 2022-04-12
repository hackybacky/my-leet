class Solution {
public:
    vector<vector<int>>board;
    int n ,m;
    bool check(int i , int j ,vector<vector<int>> board){
        if(i<0 or j<0 or i>=n or j >= m or abs(board[i][j])!=1 )return false;
        return true;
    }
    void gameOfLife(vector<vector<int>>& board) {
        
        n = board.size();
        m = board[0].size();
        for(int i = 0 ; i<n ; i++){
            for(int j=0 ;j<m; j++){
                int cnt=0;
                for(int l =j-1; l<=j+1; l++){
                    if(check(i-1,l,board) )cnt++;
                    if(check(i+1,l,board))cnt++;
                    
                }
                if(check(i,j-1,board))cnt++;
                if(check(i,j+1,board))cnt++;
               // cout<<cnt<<" "<<i<<" "<<j<<endl;
                if(board[i][j]==1 ){
                    if( cnt <2 or cnt>3)board[i][j]=-1;
                    
                    
                }
                else if(board[i][j]==0){
                    if(cnt==3){
                        
                        board[i][j]=2;
                        //cout<<"hello"<<endl;
                    }
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==-1)board[i][j]=0;
                else if(board[i][j]==2)board[i][j]=1;
            }
        }
    }
};