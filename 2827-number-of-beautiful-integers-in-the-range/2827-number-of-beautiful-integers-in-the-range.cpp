class Solution {
public:
    int dp[12][12][2][21][11][2];
    int recur(int i , int cnto  ,int take , int k , string& high , int sum,int len , int first){
        if(i == high.size()){
            int sz = len;
            
            if(sz % 2 == 1 or len == 0)return 0;
            // if(sz == 2){
            //     // cout <<second << " "<<third << " "<<len<< " " <<cnto <<endl;
            //     return cnto == sz / 2 and (second *10 + third )% k == 0;
            // }
            return cnto == sz / 2 and sum == 0;
        }
        int cur = dp[i][cnto][take][sum][len][first];
        if(cur != -1)return cur;
        cur = (high[i] - '0');
        int maxi = cur;
        if(take)maxi = 9;
        int ans = 0;
        // cout << maxi << " "<<i <<" "<<high[i] <<endl;
        for(int j = maxi ; j >= 0 ; j--){
            int c = cnto;
            int flag = take;
            if(j < cur)flag = true;
            int l = len;
            int f = first;
            if( first )l = len + 1;
            else if(j != 0)l = len + 1 , f = 1;
            if(j % 2 == 0 and f)c++;
            ans = (ans + recur(i + 1 , c , flag , k , high , (sum * 10 + j)% k , l , f));
        }
        return dp[i][cnto][take][sum][len][first] = ans;
        
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        string h = to_string(high);
        memset(dp , -1 , sizeof(dp));
        string h2 = to_string(low);
        int ans = recur(0, 0 , 0 ,k , h , 0 ,0 , 0);
        memset(dp , -1 ,sizeof(dp));
        ans -=  recur(0, 0 , 0 ,k , h2 , 0 ,  0 , 0) ;
        int cnto = 0;
        for(int i = 0 ; i < h2.size() ; i++){
            if((h2[i] - '0')% 2 == 1)cnto++;
        }
        // cout << cnto<<endl;
        if(h2.size() - cnto == cnto and low % k == 0)ans++;
        return ans;
    }
};