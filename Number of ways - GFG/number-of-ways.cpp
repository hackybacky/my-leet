// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long dp[100];
    long long int recur(int i , int n ){
        if(i==n)return 1;
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        
        long long ans = recur(i+1,n) +recur(i+4,n);
        
        return dp[i]=ans;
    }
    long long int arrangeTiles(int N){
        // code here
        
        memset(dp,-1,sizeof(dp));
        return recur(0,N);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.arrangeTiles(N)<<"\n";
    }
    return 0;
}  // } Driver Code Ends