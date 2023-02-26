class Solution {
public:
    
    // int recur(int i, int j , string& word1 , string &word2){
    //     if(j==word2.size())return word1.size()-i;
    //     if(i==word1.size())return word2.size()-j;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int ans = INT_MAX;
    //     if(word1[i]==word2[j]){
    //         ans=recur(i+1,j+1,word1,word2);
    //     }
    //     ans=min(ans,1+recur(i,j+1,word1,word2));
    //     ans=min(ans,1+recur(i+1,j,word1,word2));
    //     ans=min(ans,1+recur(i+1,j+1,word1,word2));
    //     return dp[i][j]=ans;
    // }
    int minDistance(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(j==0)dp[i][j]=i;
                else if(i==0)dp[i][j]=j;
                else{
                    if(word1[i-1]==word2[j-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }
                    dp[i][j]=min(dp[i][j],1+dp[i][j-1]);
                    
                    dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                    dp[i][j]=min(dp[i][j],1+dp[i-1][j-1]);
                }
            }
        
        }
        
        return dp[n][m];
    }
};