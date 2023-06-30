class Solution {
public:
    vector<vector<int>> dp;
    vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0 , 1, -1};
    int recur(int i , int j , vector<vector<int>> &grid){
        if(i < 0 or j < 0 or i >= grid.size() or j >= grid[0].size() or grid[i][j] == 1)return 0;
        if(i == grid.size() - 1)return 1;
        if(dp[i][j] == 1)return 0;
        dp[i][j] = 1;
        int ans = 0;
        for(int k = 0 ; k < 4 ; k++){
            int nx = x[k] + i;
            int ny = y[k] + j;
            ans |= recur(nx , ny , grid);
        }
        return ans;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 0 , high = cells.size();
        int n = row , m = col;
        int fans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            vector<vector<int>>grid(row , vector<int>(col , 0));
            for(int i = 0 ; i < mid ; i++){
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }
            dp.assign(n , vector<int>(m , -1));
            int ans = 0;
            for(int i = 0 ; i < m ; i++){
                ans |= recur(0 , i , grid);
            }
            if(ans){
                low = mid + 1;
                fans = mid;
            }
            else {
                high = mid -1 ;
            }
        }
        return fans;
    }
};