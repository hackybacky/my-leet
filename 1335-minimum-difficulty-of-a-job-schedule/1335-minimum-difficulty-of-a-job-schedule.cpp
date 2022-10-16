class Solution {
public:
    int dp[11][301];
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
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        memset(dp ,-1 ,sizeof(dp));
        
        int ans = recur(d , 0 , jobDifficulty);
        if(ans >= 1e6){
            return -1;
        }
        return ans;
    }
};