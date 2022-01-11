class Solution {
public:
    int dp[32][32];
    int n,m;
bool f(int i,int j,string &s1,string &s2){
    //const init
    // base case
    if(j>=m and i>=n) return 1;
    if(j>=m) return 0;
    //dynamic programming conversion
    if(dp[i][j]!=-1) return dp[i][j];


    // recursive logic
    bool match=(i<n and (s1[i]==s2[j] or s2[j]=='.'));
    if(j<m and s2[j+1]=='*'){
        bool ans=(f(i,j+2,s1,s2) or (match and f(i+1,j,s1,s2)));
        return dp[i][j]=ans;
    }
    if(match) return dp[i][j]=f(i+1,j+1,s1,s2);
    return dp[i][j]=0;

}


bool isMatch(string s1, string s2) {
    memset(dp,-1,sizeof dp);
    n=s1.size();m=s2.size();
        return f(0,0,s1,s2);
    }
};