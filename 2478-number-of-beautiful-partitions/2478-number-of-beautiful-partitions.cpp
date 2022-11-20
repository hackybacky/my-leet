class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[1001][1001];
    bool is_prime(char c){
        return c == '2' or c == '3' or c == '5' or c == '7';
    }
    int recur(int i , string &s , int k , int mini){
        if(i == s.size()){
            return k == 0;
        }
        if(k == 0 or s.size() - i < mini){
            return 0;
        }
        if(dp[i][k] != -1){
            return dp[i][k];
        }
        // vector<char > v = {'2' , '3' , '5' , '7'};
        
        int ans = 0;
        if(is_prime(s[i])){
            
            for(int j = i + 1; j < s.size() ;j++){
                if(is_prime(s[j]) == false and j - i + 1 >= mini){
                    ans = (ans + recur(j + 1 , s, k - 1, mini )) % mod;
                }
            }
        }
        return dp[i][k] = ans;
        
        // if(s[i] == '2' or s[i] == '3' or s[i] == '5' or s[i] == '7'){
        //     int j = i + 1;
        //     while(j < s.size() and s[j] != '2' and s[j] != '3' and s[j] != '5' and s[j] != '7'){
        //         j++;
        //     }
        //     if(j - i >= mini)
        //     ans = recur(j , s , k - 1, f , mini);
        // }
        
        
        
    }
    int beautifulPartitions(string s, int k, int minLength) {
        
        memset(dp , -1 ,sizeof(dp));
        
        return recur(0 , s , k , minLength);
    }
};