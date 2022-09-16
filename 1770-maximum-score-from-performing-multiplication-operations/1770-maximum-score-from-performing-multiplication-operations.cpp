class Solution {
public:

    vector<vector<int>>dp;
    int n;
    int recur(int l  , int cur  , vector<int>&nums ,vector<int>&mul){
        if(cur == mul.size()){
            return 0;
        }
        int r = n - 1 -(cur - l);
        if(l > r)return 0;
        if(dp[cur][l] != INT_MIN)return dp[cur][l];
        
        int ans = nums[l] * mul[cur] + recur(l+1 , cur +1 , nums , mul);
        ans = max(ans , nums[r] * mul[cur] +recur(l , cur + 1 , nums , mul));
        return dp[cur][l] = ans;
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // memset(dp , -1 ,sizeof(dp));
        n = nums.size();
        int m = multipliers.size();
        dp.assign(m , vector<int>(m,INT_MIN));
        return recur(0  , 0  , nums ,multipliers);
    }
};