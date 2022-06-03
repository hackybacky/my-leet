// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(long long s, long long n, long long x, long long a[])
    {   
        vector<long long > past;
        long long su = s;
        past.push_back(s);
        int i=0;
        while(su<x and i<n){
            a[i]+=su;
            su+=a[i];
            
            i++;
        }
        if(su==x)return 1;
        if(su<x)return 0;
        i--;
        while(x>0 and i>=0 ){
            if(x>=a[i])x-=a[i];
            if(x==0 )
            return 1;
            i--;
        }
        return x==s;
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}  // } Driver Code Ends