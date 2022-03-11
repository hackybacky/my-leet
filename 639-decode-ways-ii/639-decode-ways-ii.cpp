class Solution {
public:
    int n ;
    vector<int> dp;
    string s;
    long long mod = 1e9+7;
    long long recur(int i ){
        if(i>n)return 0;
        if(i==n)return 1;
        if(s[i]=='0')return 0;
        
        if(dp[i]!=-1)return dp[i];
        
        long long a=recur(i+1);
        if(s[i]=='*')a=9*a;
        
        
        long long b =0;
        if(i+1<n ){
            // if(s[i]=='*' and s[i+1]=='*')b=25*recur(i+2);
            // else if((s[i]=='1' or s[i]=='2') and s[i+1]=='*'){
            //     b=((s[i]=='1')?9:6)*recur(i+2);
            // }
            // else if(s[i]=='*' and s[i+1]-'0'<=6){
            //     b=2*recur(i+2);
            // }
            // else if((s[i]=='1' and s[i+1]-'0'<=9) or (s[i]=='2' and s[i+1]-'0'<=6)){
            //     b=recur(i+2);
            // }
            // else if(s[i]=='*') b=(recur(i+2));
            if(s[i]=='*' && s[i+1]=='*'){
                b=15*recur(i+2);
            }else if((s[i]=='1' || s[i]=='2') && s[i+1]=='*'){
                b=(s[i]=='1'?9:6)*recur(i+2);
            }else if(s[i]=='*' && s[i+1]-'0'<=6){
                b=2*(recur(i+2));
            }else if((s[i]=='1' && s[i+1]-'0'<=9)||(s[i]=='2' && s[i+1]-'0'<=6)){
               // cout<<"called"<<endl;
                b=recur(i+2);
            }else if(s[i]=='*'){
                b=recur(i+2);
            }
        }
        return dp[i]=(a+b)%mod;
    }
    
    int numDecodings(string S) {
        n=S.size();
        dp.assign(n+1,-1);
        s=S;
        int ans = recur(0);
       
        return ans;
    }
};