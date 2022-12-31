class Solution {
public:
    int dp[101][101];
    bool recur(int i , int j , string & s , string & p){
        if(i == s.size() and j == p.size())return 1;
        if(j == p.size())return 0;
        if(dp[i][j] != -1)return dp[i][j];
        // if(i == s.size()){
        //     if(j < p.size() - 2)return false;
        //     return p[j] == '*' or p[j + 1] == '*';
        // }
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
        memset(dp , -1 ,sizeof(dp));
        return recur(0 , 0 , s , p);
    }
};