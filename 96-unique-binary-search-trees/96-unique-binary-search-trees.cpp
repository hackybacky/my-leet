class Solution {
public:
    int N;
  //  int ans=0;
    int dp[20];
    int recur(int  n){
      //  cout<<n<<endl;
        
        if(n<=1)return 1;
        if(dp[n]!=-1)return dp[n];
        int ans=0;
        for(int i=1; i<=n; i++ ){
            ans+=recur(i-1)*recur(n-i);
        }
        return dp[n]= ans;
    }
    int numTrees(int n) {
        N=n;
        memset(dp,-1,sizeof(dp));
        return recur(n);
    }
};