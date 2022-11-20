class Solution {
public:
    const int mod = 1e9 + 7;
    int dp[1001][1001];
    bool is_prime(char c){
        return c == '2' or c == '3' or c == '5' or c == '7';
    }
    int recur(int i , string &s , int k , int mini){
        if(i == s.size() - 1){
            // cout << s[i] << endl;
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
            if(is_prime(s[j]) and j - i >= mini and is_prime(s[j - 1]) == false){
                ans = (ans + recur(j  , s, k - 1, mini )) % mod;
            }
        }
        }
        // }
        return dp[i][k] = ans;
        
     
        
        
    }
    int beautifulPartitions(string s, int k, int minLength) {
        
        memset(dp , -1 ,sizeof(dp));
        s += "7";
        return recur(0 , s , k , minLength);
    }
};