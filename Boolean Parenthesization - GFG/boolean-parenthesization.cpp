// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[201][201][2];
    int mod = 1003;
    int recur(int i  ,int j ,string s , int t){
        if(i>j)return 0;
        if(i==j){
            if(t)
            return s[i]=='T'?1:0;
            return s[i]=='F'?1:0;
        }
        if(dp[i][j][t]!=-1)return dp[i][j][t];
        int ans=0;
        for(int k=i+1;k<j;k+=2){
            // if(s[k]!='T' or s[k]!='F'){
                
                int lt = recur(i,k-1,s,1);
                int lf = recur(i,k-1,s,0);
                int rt = recur(k+1,j,s,1);
                int rf = recur(k+1,j,s,0);
                
                if(s[k]=='&'){
                    if(t)ans=(ans+lt*rt)%mod;
                    else ans=(ans+lt*rf+lf*rt+lf*rf)%mod;
                }
                else if(s[k]=='|'){
                    if(t)ans=(ans+lf*rt+lt*rf+rt*lt)%mod;
                    else ans=(ans+lf*rf)%mod;
                }
                else if(s[k]=='^') {
                    if(t)ans=(ans+ lf*rt+rf*lt)%mod;
                    else ans=(ans+ lf*rf+lt*rt)%mod;
                }
                
            // }
            
        }
        dp[i][j][t]=ans;
    }
    
    int countWays(int N, string S){
        // code here
        memset(dp,-1,sizeof(dp));
        int ans=  recur(0,N-1,S,true);
       // for(int i=0; i<100; i++)for(int j=0; j<100; j++)cout<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
        return ans;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends