class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        
        dp[0]=nums[0];
        
        for(int i=1 ; i<n; i++){
            
            int prev = dp[i-1];
            int sprev = (i-2>=0?dp[i-2]:0)+nums[i];
            
            dp[i]=max(prev,sprev);
        }
        return dp[n-1];
    }
};