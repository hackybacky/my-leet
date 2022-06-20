class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        bool flag=false,flag2=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 and matrix[i][j]==0)flag=true;
                if(j==0 and matrix[i][j]==0)flag2=true;
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][0]==0 or matrix[0][j]==0)matrix[i][j]=0;
                
            }
        }
        if(flag)for(int i=0;i<m;i++)matrix[0][i]=0;
        if(flag2)for(int j=0;j<n;j++)matrix[j][0]=0;
        // return matrix;
    }
};