class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[31][1001];
    int numRollsToTarget(int n, int k, int target) {
        
        // memset(dp , -1 ,sizeof(dp));
        dp[0][0] = 1;
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j <= target ; j++){
                
                for(int l = 1 ; l <= k ; l++){
                    if(j - l >=0 )
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - l])%mod;
                }
                
            }
        }
        return dp[n][target];
    }
};