class Solution {
public:
    string s;
    int n;
    int dp[501][501];
    int recur(int l , int r){
        if(r<=l)return 0;
        
        if(dp[l][r]!=-1)return dp[l][r];
        int ans =1e8;
        int ans3=1e8;
        int ans2=1e8;
        if(s[l]==s[r])ans=recur(l+1,r-1);
        else {
            ans2= 1+min(recur(l+1,r),recur(l,r-1));
            int k =r;
          //  while(k>l and s[l]!=s[k])k--;
            
          //  if(k>l)ans3=(r-k+1)+recur(l+1,k-1);
        }
       // cout<<ans<< " "<<ans2<<" "<<ans3<<endl;
        return dp[l][r]=min({ans,ans2,ans3});
        
        
    }
    int minInsertions(string S) {
        n = S.size();
        
        s=S;
        
        memset(dp,-1,sizeof(dp));
        
        return recur(0,n-1);
    }
};