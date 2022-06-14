class Solution {
public:
    int numDistinct(string s, string t) {
         int n=s.size();
         int m=t.size();
       
         int dp[n][m];
        memset(dp,-1,sizeof(dp));
    
        function<int(int,int)> recur=[&](int i, int j ){
            if(j==m)return 1;
            if(i==n)return 0;

            if(dp[i][j]!=-1)return dp[i][j];

            int ans=0;

            if(s[i]==t[j]){
                ans+= recur(i+1,j+1) + recur(i+1,j);
            }
            else ans+=recur(i+1,j);
            return dp[i][j]=ans;
        };
        return recur(0,0);
    }
//     int numDistinct(string s, string t) {
        
//         int n = t.size();
//         int m = s.size();
        
//         int dp[n+1][m+1];
//         memset(dp,0,sizeof(dp));
        
//         for(int i=0 ; i<=m ; i++){
//             for(int j=0;j<=n; j++){
//                 if (i==0)dp[i][j]=0;
//                 else if(j==0)dp[i][j]=0;
//                 else {
//                     dp[i][j]+=dp[i][j-1];
//                     if(s[i-1]==t[j-1])dp[i][j]+=dp[i-1][j-1];
                    
//                 }
//             }
//         }
//         return dp[n][m];
//     }
};