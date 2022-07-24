class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0 , j=0;
        while(i<m ){
            if(matrix[i][j]==target){
                return true;
            }
            while(j<n and matrix[i][j]<target ){
                j++;
            }
            while(j<n and j>=0 and matrix[i][j]>target )j--;
            
            if(j==-1)return false;
            if(j==n)j=n-1;
            if(matrix[i][j]==target){
                return true;
            }
            i++;
        }
        
        cout<<i<<" "<<j<<endl;
        return false;
    }
};