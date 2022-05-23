class Solution {
public:
    int n ,m;
    int dp[601][101][101];
    int recur(int i , int taken , int tn,int tm,vector<string>&strs){
        if(i==strs.size())return 0;
        if(dp[i][tn][tm]!=-1)return dp[i][tn][tm];
        auto it = strs[i];
        int one = count(it.begin(),it.end(),'1');
        int z = it.size()-one;
        int ans=0;
        if(tn+one<=n and tm+z<=m){
            ans=1+recur(i+1,1,tn+one,tm+z,strs);
        }
        ans=max(ans,recur(i+1,0,tn,tm,strs));
        return dp[i][tn][tm]=ans;
    }
    int findMaxForm(vector<string>& strs, int M, int N) {
        m=M;
        memset(dp,-1,sizeof(dp));
        n=N;
       return recur(0,0,0,0,strs);
    }
};