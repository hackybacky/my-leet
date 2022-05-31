class Solution {
public:
    int n ,m;
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    bool ans;
    vector<vector<char>> board;
    bool backtrack(vector<vector<char>>&b ,int i , int j , int indi, string &word){
        
        
        if(indi==word.size())return true;

        if(i<0 or j<0 or i>=n or j>=m )return false;
        if(b[i][j]=='V' or b[i][j]!=word[indi])return false;
        bool ans=false;
        
        for(int k=0; k<4; k++){
            int nx = i+x[k];
            int ny = j + y[k];
            
            char c = b[i][j];
            b[i][j]='V';
            ans|=backtrack(b,nx,ny,indi+1,word);
            b[i][j]=c;
        }
        return ans;
    }
    
    bool exist(vector<vector<char>>& b, string word) {
        
        board=b;
        n = board.size();
        m = board[0].size();
        ans=false;
        for(int i =0; i<n ; i++){
            for(int j=0; j<m; j++){
                if(backtrack(b,i,j,0,word))return true;
            }
        }
        return false;
        
    }
};