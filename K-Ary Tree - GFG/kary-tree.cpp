// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    const long long mod = 1e9+7;
    long long givepow(long long n, long long x){
        if(x==0)return 1;
        if(x==1)return n;
        
        long long res = givepow(n,x/2);
        if(x%2==1){
            return (((res*res)%mod)*n)%mod;
        }
        return (res*res)%mod;
    }
    long long karyTree(int k, int m) {
        // code here
        
        return givepow(k,m);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}  // } Driver Code Ends