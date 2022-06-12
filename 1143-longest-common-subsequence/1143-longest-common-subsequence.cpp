class Solution {
public:
    
    int dp[1001][1001];
    int recur(int i , int j ,string &t , string &st){
        
        if(i>=t.size() or j>=st.size())return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
    
        
        int ans=0;
        if(t[i]==st[j])ans=1+recur(i+1,j+1,t,st);
        ans=max(ans,recur(i+1,j,t,st));
        ans=max(ans,recur(i,j+1,t,st));
        return dp[i][j]=ans;
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        // int ans=0;
        memset(dp,-1,sizeof(dp));
        return recur(0,0,text1,text2);
        
    }
};