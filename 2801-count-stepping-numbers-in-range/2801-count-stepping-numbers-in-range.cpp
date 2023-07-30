class Solution {
public:
    int dp[101][11][2][2];
    int mod = 1e9 + 7;
    int recur(int i , int last , int flag , string &cur , int d){
        if(i == cur.size()){
            return d ;
        }
        if(dp[i][last ][flag][d] != -1)return dp[i][last][flag][d];
        int ans = 0;
        int curl = cur[i] - '0';
        int maxi = curl;
        if(flag){
            maxi = 9;
        }
        
        for(int j = 0 ; j <= maxi ; j++){
            int nflag = true;
            // if(i == 0 and j == 0)continue;
            if(abs(last - j) != 1 and d != 0 )continue;
            if(j == curl and !flag)nflag = false;
            int nd = 0 ;
            if(j != 0 )nd = 1;
            ans = (ans + recur(i + 1 , j , nflag , cur ,nd | d))% mod;
        }
        return dp[i][last ][flag][d] = ans % mod;
    }
    int solve(string high){
        memset(dp , -1 , sizeof(dp));
        int curl = high[0] - '0';
        int ans = 0;
        for(int i = 0 ; i <= curl  ; i++){
            bool fg = true;
            if(i == curl)fg = false;
            int d = 0;
            if(i != 0)d = 1;
            ans =(ans +  recur(1 , i , fg , high , d))%mod;
        }
        return ans;
    }
    int countSteppingNumbers(string low, string high) {
        
        int ans = ((solve(high) - solve(low) + mod )%mod + 1)%mod;
        // cout << solve(high) << " " << solve(low) << endl;
        int last = low[0]-'0';
        for(int i = 1 ; i < low.size() ; i++){if(abs((low[i] - '0') - last) != 1){ans =(ans - 1+mod)%mod;break;};last = (low[i] -'0');}
        return ans;
        
    }
};