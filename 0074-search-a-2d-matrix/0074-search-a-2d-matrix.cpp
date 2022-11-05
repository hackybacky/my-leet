class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int l = 0 , r = n * m - 1;
        while(l <= r){
            int mid = (l + r)/2;
            int col = mid % m;
            int row = mid / m;
            int cur = matrix[row][col];
            if(cur > x){
                r = mid - 1;
            }
            else if(cur < x){
                l = mid + 1;
            }
            else{
                return 1;
            }
        }
        return 0;
    }
};