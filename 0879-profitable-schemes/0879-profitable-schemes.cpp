class Solution {
public:
    int dp[101][101][101];
    int minprofit , N;
    const int mod = 1e9 + 7;
    int recur(int i , int pro , int mem ,vector<int>&group , vector<int>&profit){
        if(i == group.size()){
            return pro >= minprofit and mem <= N;
        }
        if(mem > N)return 0;
        if(pro >= 100)pro = 100;
        if(dp[i][pro][mem] != -1)return dp[i][pro][mem];
        int ans = 0 ;
        int take = recur(i + 1 , pro + profit[i],mem + group[i] , group , profit);
        int ntake = recur(i + 1 , pro , mem , group , profit);
        ans = (ans + take )% mod;
        ans = (ans + ntake )% mod;
        return dp[i][pro][mem] = ans % mod;     
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp , -1 ,sizeof(dp));
        minprofit = minProfit , N = n;
        return recur(0 , 0 , 0 , group , profit);
    }
};