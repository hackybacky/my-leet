class Solution {
public:
    
    int dp[50001][2];
    int recur(int i , int j , vector<int>&stoneValue){
        if(i >= stoneValue.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = INT_MIN;
        int cur = 0;
        for(int index = i ; index < min(i + 3 , (int)stoneValue.size()) ; index++){
            cur += stoneValue[index];
            ans = max(ans , cur - recur(index + 1 ,j ^ 1 , stoneValue));
        }
        return dp[i][j] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        
        memset(dp , -1 ,sizeof(dp));
        int cur = recur(0 , 0 , stoneValue);
        if(cur > 0)return "Alice";
        else if(cur == 0)return "Tie";
        return "Bob";
        
    }
};