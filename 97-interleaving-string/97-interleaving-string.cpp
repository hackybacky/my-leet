class Solution {
public:
    int dp[2][101];
    
   
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        memset(dp,0,sizeof(dp));
        int n = s1.size();
        int m = s2.size();
        dp[0][0]=1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 and j==0)dp[i][j]=1;
                else if(i==0 ){
                    dp[i&1][j]=((s2[j-1]==s3[j-1+i]) and dp[i&1][j-1]);
                }
                else if(j==0 ){
                    dp[i&1][j]=((s1[i-1]==s3[i-1+j]) and dp[(i-1)&1][j]);
                
                }
                else{
                    dp[i&1][j]=(dp[i&1][j-1] and s2[j-1]==s3[i+j-1])||(dp[(i-1)&1][j] and s1[i-1]==s3[i+j-1]);
                }
                
            }
        }
        return dp[n&1][m];
    }
};