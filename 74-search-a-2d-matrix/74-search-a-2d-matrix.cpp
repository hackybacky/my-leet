class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int row=0;
        for(int i=0; i<n ; i++){
            if(matrix[i][0]<=target and matrix[i][m-1]>=target){
                row=i;
                break;
            }
        }
        
        return binary_search(matrix[row].begin(),matrix[row].end(),target);
    }
};