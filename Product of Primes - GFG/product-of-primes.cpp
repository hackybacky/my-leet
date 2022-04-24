// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool sieve(int r ){
        for(int i=2; i*i<=r; i++){
            if(r%i==0)return false;
        }
        return true;
    }
    long long primeProduct(long long l, long long r){
        // code here
        long long int ans =1;
        int mod = 1e9+7;
        for(int i=l; i<=r; i++){
            if(sieve(i)){
                ans=(ans*i)%mod;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}  // } Driver Code Ends