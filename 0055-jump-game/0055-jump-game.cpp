class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            
            int cur = nums[i];
            if(dp[i]==0)continue;
            for(int j=i+1;j<=i+cur and j<n ;j++){
                dp[j]=1;
            }
        }
        return dp[n-1];
    }
};