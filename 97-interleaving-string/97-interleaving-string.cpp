class Solution {
public:
    int dp[101];
    
   
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        memset(dp,0,sizeof(dp));
        int n = s1.size();
        int m = s2.size();
        dp[0]=1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 and j==0)dp[j]=1;
                else if(i==0 ){
                    dp[j]=((s2[j-1]==s3[j-1+i]) and dp[j-1]);
                }
                else if(j==0 ){
                    dp[j]=((s1[i-1]==s3[i-1+j]) and dp[j]);
                
                }
                else{
                    dp[j]=(dp[j-1] and s2[j-1]==s3[i+j-1])||(dp[j] and s1[i-1]==s3[i+j-1]);
                }
                
            }
        }
        return dp[m];
    }
};