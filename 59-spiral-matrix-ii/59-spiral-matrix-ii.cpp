class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int row = 0 ,col=0 , lrow  = n-1 ,lcol=n-1;
        vector<vector<int>> mat(n,vector<int>(n,0));
        int cnt=1;
        while(row<=lrow and col <= lcol){
            int crow = row , ccol = col;
            
            while(ccol<=lcol){
                mat[crow][ccol]=cnt++;
                ccol++;
            }
            if(row==lrow)break;
            
            crow = row+1;
            ccol = lcol;
            while(crow<=lrow){
                mat[crow][ccol]=cnt++;
                crow++;
            }
            ccol = lcol-1;
            crow = lrow;
            while(ccol>=col){
                mat[crow][ccol]=cnt++;
                ccol--;
            }
            crow=lrow-1;
            ccol=col;
            while(crow>row){
               // cout<<"hello"<<endl;
                mat[crow][ccol]=cnt++;
                crow--;
            }
            row++,col++,lcol--,lrow--;
        }
        return mat;
    }
};