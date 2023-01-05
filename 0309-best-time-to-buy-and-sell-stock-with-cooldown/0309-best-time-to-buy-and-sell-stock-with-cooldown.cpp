class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        // memset(dp,0,sizeof(dp));
        int n = prices.size();
        int agla1 = 0 ;
        int twoagla0 = 0;
        int agla0 = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            int cur0 = 0  , cur1 = 1;
            for(int j = 0 ; j < 2 ; j++){
                int ans = 0;
                if(j == 0){
                    cur0 = agla0;
                    ans = -prices[i] + agla1;
                    cur0 = max(cur0 , ans);
                }
                else  ans = prices[i] + twoagla0 , cur1 = max(ans , agla1);
            }
            twoagla0 = agla0;
            agla0 = cur0;
            agla1 = cur1;
        }
        return agla0;
    }
};