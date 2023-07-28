class Solution {
public:
    int dp[21][21][2];
    vector<int>nums;
    int recur(int left , int right ,int turn ){
        if(left > right)return 0;
        if(dp[left][right][turn] != INT_MIN)return dp[left][right][turn];
        int ans = 0;
        if(turn % 2 == 0){
            ans = max(nums[left] + recur(left + 1 , right , turn ^ 1) , nums[right]+recur(left , right - 1 , turn ^ 1));
        }
        else{
            ans = min(-nums[left] + recur(left + 1 , right , turn ^ 1) , -nums[right] + recur(left , right - 1 , turn ^ 1));
        }
        return dp[left][right][turn] = ans;
        
    }
    bool PredictTheWinner(vector<int>& num) {
        // memset(dp , INT_MIN ,sizeof(dp));
        for(int i = 0 ; i < 21 ; i++)for(int j = 0 ; j < 21 ; j++)for(int k = 0 ; k < 2 ;  k++)dp[i][j][k] = INT_MIN;
        nums = num;
        int n = nums.size();
        int ans = recur(0 , n - 1 , 0);
        cout << ans << endl;
        if(ans < 0)return false;
        return true;
    }
};