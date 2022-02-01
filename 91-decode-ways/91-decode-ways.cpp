class Solution {
public:
    bool check(string a){
        if(a[0]=='0')return false;
        int c=stoi(a);
        if(c>=1 and c<=26)return true;
        return false;
    }

    int numDecodings(string s) {
       
        int n=s.size();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]= (s[0]-'0')>0?1:0;
        
        for(int i=2;i<=n; i++){
            if(check(s.substr(i-2,2))){
                dp[i]+=dp[i-2];
            }
            if(check(s.substr(i-1,1))){
                dp[i]+=dp[i-1];
            }
        }
        for(auto it : dp)cout<<it <<" ";
        return dp[n];
    }
};