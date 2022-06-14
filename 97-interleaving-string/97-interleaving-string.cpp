class Solution {
public:
    int dp[101][101];
    
    int recur(int i ,int j , string &s , string s2, string s3){
        if(i==s.size()){
            return s3.substr(i+j)==s2.substr(j);
        }
        if(j==s2.size()){
             return s3.substr(i+j)==s.substr(i);
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=false;
        if(s[i]==s3[i+j]){
            ans|=(recur(i+1,j,s,s2,s3));
        }
        if(s2[j]==s3[i+j]){
            ans|=recur(i,j+1,s,s2,s3);
        }
        return dp[i][j]=ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return recur(0,0,s1,s2,s3);
    }
};