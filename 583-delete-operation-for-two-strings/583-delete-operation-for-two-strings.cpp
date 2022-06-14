class Solution {
public:
    
    int minDistance(string word1, string word2) {
        if(size(word1) < size(word2)) swap(word1, word2);
        int dp[501][501];
        memset(dp,INT_MAX,sizeof(dp));
        int n = word1.size();
        int m = word2.size();
        for(int i=0;i<=n; i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0)dp[i&1][j]=i+j;
                else
                dp[i & 1][j] = word1[i - 1] == word2[j - 1] ? dp[(i - 1) & 1][j - 1] : 1 + min(dp[(i - 1) & 1][j], dp[i & 1][j - 1]);
            }
                                                                                                              }
        return dp[n&1][m];
    }
};