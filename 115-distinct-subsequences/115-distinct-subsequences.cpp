class Solution {
public:
    int numDistinct(string s, string t) {
        
        int n = t.size();
        int m = s.size();
        
        unsigned long long int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=0 ; i<=n ; i++){
            for(int j=0;j<=m; j++){
                if(i==0 and j==0)dp[i][j]=1;
                else if (j==0)dp[i][j]=0;
                else if(i==0)dp[i][j]=1;
                else {
                    if(j-1>=0)dp[i][j]+=dp[i][j-1];
                    if(s[j-1]==t[i-1])dp[i][j]+=dp[i-1][j-1];
                    
                }
            }
        }
        return dp[n][m];
    }
};