class Solution {
public:
    int dp[1001][1001];
    int ispal( int l , int r ,string s ){
        if(l>=r)return 1;
        
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=0;
        if(s[l]==s[r]){
            ans=ispal(l+1,r-1,s);
        }
        
        return dp[l][r]=ans;
    }
    int countSubstrings(string s) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<s.size(); i++){
            for(int j=i;j<s.size(); j++){
                if(ispal(i,j,s))ans++;
            }
        }
        return ans;
    }
};