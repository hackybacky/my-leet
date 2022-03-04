class Solution {
public:
     vector<int> x = {1, -1, 0, 0};
   vector<int> y = {0, 0, 1, -1};
    int n,m;
    void dfs(int i,int j,vector<vector<char>> &board){
        if(i<0 or j<0 or i>=n or j>=m or board[i][j]!='O' )return ;
        board[i][j]='*';
        for(int k=0; k<4; k++){
            int nx = i+ x[k];
            int ny = j+ y[k];
            
            dfs(nx,ny,board);
        }
        
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m = board[0].size();
        for(int i=0; i<n ;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board);
            }
            if(board[i][m-1]=='O')dfs(i,m-1,board);
        }
        for(int i=0; i<m ;i++){
            if(board[0][i]=='O'){
                dfs(0,i,board);
            }
            if(board[n-1][i]=='O')dfs(n-1,i,board);
        }
        for(auto &it : board){
            for(auto &i : it){
                if(i=='O'){i='X';}
                if(i=='*')i='O';
            }
        }
        
    }
};