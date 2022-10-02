class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[31][1001];
    int recur(int i , int sum , int k ){
        if(sum == 0){
            return i == 0;
        }
        if(i == 0 or sum < 0)
            return 0;
        if(dp[i][sum] != -1)
            return dp[i][sum];
        int ans = 0;
        for(int j = 1 ; j <= k ;j++){
            ans = (ans + recur(i - 1 , sum - j , k)) % mod;
        }
        return dp[i][sum] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        
        // memset(dp , -1 ,sizeof(dp));
        dp[0][0] = 1;
        
        for(int i = 1 ; i <= n ; i++){
            for(int j = 0 ; j <= target ; j++){
                if(j == 0 and i==0)
                    dp[i][j] = 1;
                else{
                    for(int l = 1 ; l <= k ; l++){
                        if(j - l >=0 )
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - l])%mod;
                    }
                }
            }
        }
        return dp[n][target];
    }
};