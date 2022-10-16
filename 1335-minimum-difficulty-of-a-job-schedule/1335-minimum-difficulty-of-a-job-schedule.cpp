class Solution {
public:
    int dp[311][12];
    int recur(int current_day , int index , vector<int>&dif){
        if(index == dif.size()){
            return current_day == 0 ? 0 : 1e6;
        }
        
        if(current_day <=0 ){
            return 1e6;
        }
        
        if(dp[current_day][index] != -1){
            return dp[current_day][index];
        }
        
        int maxi =INT_MIN;
        int ans = INT_MAX;
        
        for(int j = index ; j < dif.size() ; j++){
            maxi = max(maxi , dif[j]);
            ans = min(ans , maxi + recur(current_day - 1, j + 1 , dif));
        }
        
        return dp[current_day][index] = ans;
    }
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