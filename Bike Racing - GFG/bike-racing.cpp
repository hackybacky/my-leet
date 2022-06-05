// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long buzzTime(long N, long M, long L, long H[], long A[])
    {
        // code here
        long long int l=0,r=1e18;
        long long ans=1e12;
        while(l<=r){
            long long int mid = l+(r-l)/2;
            bool flag=false;
            long long fast=0;
            for(int i=0 ; i<N ; i++){
                long long cur = (long long)A[i]*mid+H[i];
                if(cur>=L)fast+=cur;
                if(fast>=M){
                    flag=true;break;
                }
            }
            if(flag)ans=min(ans,mid),r=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends