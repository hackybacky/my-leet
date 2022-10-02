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
        
        memset(dp , -1 ,sizeof(dp));
        
        return recur(n , target , k);
    }
};