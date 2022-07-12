// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int n ,m;
    int dp[501][501];
    int recur(int i , int j ,string & s , string & t){
        if(i>=n )return 1e5;
        
        if(j==m)return 1;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans;
        int k=j;
        for( k=j;k<m;k++){
            if(t[k]==s[i]){
                break;  
            }
        }
        if(k==m)return 1;
        ans =1+recur(i+1,k+1,s,t);
        ans=min(ans,recur(i+1,j,s,t));
        return dp[i][j]=ans;
    }
    int shortestUnSub(string S, string T) {
        // code here
        n = S.size();
        m = T.size();
        memset(dp,-1,sizeof(dp));
        
        int ans=recur(0,0,S,T);
        if(ans==1e5)return -1;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends