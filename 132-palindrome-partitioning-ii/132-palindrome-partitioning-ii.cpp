class Solution {
public:
    int pal[2001][2001];
    int isPal(string &s , int l , int r ){
        if(l>=r)return pal[l][r]= 1;
        if(pal[l][r]!=-1)return pal[l][r];
        
        bool cur = true;
        if(s[l]==s[r]){
            cur&=isPal(s,l+1,r-1);
        }
        else cur=false;
        isPal(s,l,r-1);
        isPal(s,l+1,r);
        return pal[l][r]=cur;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        memset(pal,-1,sizeof(pal));
        isPal(s,0,n-1);
        // cout<<pal[8][9]<<endl;
        for(int i=1;i<=n;i++){
            string cur="";
            for(int j=i;j<=n;j++){
                cur+=s[j-1];
                if(pal[i-1][j-1]==1){
                    if(dp[i-1]!=INT_MAX){
                        dp[j]=min(dp[j],dp[i-1]+1);
                    }
                }
            }
        }
        return dp[n]-1;
    }
};