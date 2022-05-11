class Solution {
public:
    int dp[51][6];
    int N;
    int recur(int i , int last ){
        if(i==N)return 1;
        
        if(dp[i][last]!=-1)return dp[i][last];
        int ans=0;
        for(int j=last; j<=5; j++){
            ans+=recur(i+1,j);
        }
        return dp[i][last]=ans;
    }
    int countVowelStrings(int n) {
        N=n;
        memset(dp,-1,sizeof(dp));
        return recur(0,1);
    }
};