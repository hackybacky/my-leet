class Solution {
public:
    int n,m,k;
    int dp[101][101][101];
    const int mod = 1e9+7;
    int recur(int maxi , int  i , int j ){
        if(i==n){
            //cout<<j<<" "<<k<<endl;
            return k==j;
        }
        if(j>k)return 0;
        if(dp[i][j][maxi]!=-1)return dp[i][j][maxi];
        int ans=0;
        for(int p =1; p<=m; p++){
            if(p>maxi){
                ans=(ans+recur(p,i+1,j+1))%mod;
            }
            else{
                ans=(ans+recur(maxi,i+1,j))%mod;
            }
        }
       // cout<<" hello "<<ans<<endl;
        return dp[i][j][maxi]=ans%mod;
    }
    int numOfArrays(int N, int M, int K) {
        n=N;
        m=M;
        k=K;
        memset(dp,-1,sizeof(dp));
        return recur(0,0,0);
    }
};