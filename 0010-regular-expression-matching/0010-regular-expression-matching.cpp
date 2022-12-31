class Solution {
public:
    int dp[101][101];
    bool recur(int i , int j , string & s , string & p){
        if(i == s.size() and j == p.size())return 1;
        if(j == p.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        bool match = (i < s.size() and (s[i] == p[j] or p[j ] == '.'));
        bool ans = true;
       if(j + 1< p.size() and p[j + 1] == '*'){
            if(match){
                ans &= recur(i + 1, j , s, p) | recur(i + 1 , j + 2, s, p) | recur(i , j + 2, s, p);
            }
            else{
                ans &= recur(i , j + 2 , s, p);
            }
        }
        else{
            if(match)ans &= recur(i + 1, j +1 ,s , p);
            else ans = false;
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        memset(dp , 0 ,sizeof(dp));
        int n = s.size() , m = p.size();
        dp[n][m] = 1;
        
        for(int i = n ; i >= 0  ; i--){
            for(int j =  m - 1 ; j >= 0 ; j--){
                bool match = (i < s.size() and (s[i] == p[j] or p[j ] == '.'));
                 bool ans = true;
               if(j + 1< p.size() and p[j + 1] == '*'){
                    if(match){
                        ans &= dp[i + 1][j] or dp[i + 1][j + 2 ] or dp[i][j + 2];
                        // ans &= recur(i + 1, j , s, p) | recur(i + 1 , j + 2, s, p) | recur(i , j + 2, s, p);
                    }
                    else{
                        ans &= dp[i][j + 2];
                        // ans &= recur(i , j + 2 , s, p);
                    }
                }
                else{
                    if(match)ans &= dp[i + 1][j + 1];
                    else ans = false;
                }
                dp[i][j] = ans;
            }
        }
        return recur(0 , 0 , s , p);
    }
};