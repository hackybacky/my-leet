class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int used[9][9]={0},used2[9][9]={0},used3[9][9]={0};
        
        for(int i=0 ; i<9 ; i++){
            for(int j=0  ; j<9 ; j++){
                if(board[i][j]!='.'){
                    
                    int num = board[i][j]-'0'-1;
                    int k= i/3*3+j/3;
                    
                    if(used[i][num] or used2[j][num] or used3[k][num]){
                        cout<<i<<" "<<j<<" "<<k;
                        
                        return false;
                    }
                    
                    used[i][num]=used2[j][num]=used3[k][num]=1;
                }
            }
        }
        return true;
    }
};