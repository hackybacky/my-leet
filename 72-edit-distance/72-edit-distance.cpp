class Solution {
public:
    int dp[501][501];
    int recur(int i, int j , string& word1 , string &word2){
        if(j==word2.size())return word1.size()-i;
        if(i==word1.size())return word2.size()-j;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = INT_MAX;
        if(word1[i]==word2[j]){
            ans=recur(i+1,j+1,word1,word2);
        }
        ans=min(ans,1+recur(i,j+1,word1,word2));
        ans=min(ans,1+recur(i+1,j,word1,word2));
        ans=min(ans,1+recur(i+1,j+1,word1,word2));
        return dp[i][j]=ans;
    }
    int minDistance(string word1, string word2) {
        
        memset(dp,-1,sizeof(dp));
        return recur(0,0,word1,word2);
    }
};