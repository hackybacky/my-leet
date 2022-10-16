class Solution {
public:
    int dp[311][12];
  
    int minDifficulty(vector<int>& job, int d) {
        memset(dp ,1e6 ,sizeof(dp));
        int n = job.size();
        dp[0][0] = 0;
        // for(int i = 0 ; i <=d ; i++)
        //     dp[0][j] = 0;
        for(int i = 1 ; i <= n ; i++){
            int maxi = 0;
            
            for(int j = i ; j <= n ;j++){
                maxi = max(maxi , job[j - 1]);
                for(int k = 1 ; k <= d; k++){
                    // cout  << maxi << endl;
                    dp[j][k] = min(dp[i - 1][k - 1]  + maxi, dp[j][k]);
                }
            }
            
        }
        
        int ans = dp[n][d];
        if(ans >= 1e6){
            return -1;
        }
        return ans;
    }
};