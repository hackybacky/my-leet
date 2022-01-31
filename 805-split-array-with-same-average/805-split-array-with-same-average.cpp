class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int su=accumulate(nums.begin(), nums.end(),0);
        
        
        int n=nums.size();
        vector<int > dp(su+10,0);
        
       // dp[0]=0;
       
       dp[nums[0]] = 2;
        for(int i=1; i<n; i++) {
            for(int s=su-nums[i]; s>=0; s--) {
                if(dp[s])
                    dp[s+nums[i]] |= (dp[s]<<1);
            }
            dp[nums[i]] |= 2;
        }
    
         for(int len=1; len<n; len++) {
            if( (su*len)%n == 0 && ((1<<len) & dp[su*len/n])) {
                return true;
            }
        }
        
        return false;
        
        
        
        
    }
};