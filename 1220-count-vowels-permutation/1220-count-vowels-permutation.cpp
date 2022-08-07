class Solution {
public:
    map<pair<int,char>,int>dp;
    const int mod = 1e9+7;
    int N;
    int recur(int i , char p){
        if(i==N)return 1;
        if(dp.find({i,p})!=dp.end())return dp[{i,p}];
        int ans=0;
        if(p=='a')ans=recur(i+1,'e');
        if(p=='e')ans=(recur(i+1,'a')+recur(i+1,'i'))%mod;
        if(p=='i')ans=((recur(i+1,'a')+recur(i+1,'e'))%mod+(recur(i+1,'o')+recur(i+1,'u'))%mod)%mod;
        if(p=='o')ans=(recur(i+1,'i')+recur(i+1,'u'))%mod;
        if(p=='u')ans=recur(i+1,'a')%mod;
        return dp[{i,p}]=ans%mod;
        
    }
    int countVowelPermutation(int n) {
        N=n;
        
        int ans=0;
        ans=recur(1,'a')%mod;
        ans=(ans+recur(1,'e'))%mod;
        ans=(ans+recur(1,'i'))%mod;
        ans=(ans+recur(1,'o'))%mod;
        ans=(ans+recur(1,'u'))%mod;
        return ans;
    }
};