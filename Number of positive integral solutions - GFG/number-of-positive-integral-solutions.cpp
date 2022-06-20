#include <bits/stdc++.h>
// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    
public:

long long int C(long long int n,long long  int r) {
  if(r>n)return 0;
    if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
    long long int ans = 1;
    int i;
 
    for(i = 1; i <= r; i++) {
        ans *= n - r + i;
        ans /= i;
    }
 
    return ans;
}

    long posIntSol(string s)
    {   
        int n = count(s.begin(),s.end(),'+')+1;
        int pos = s.find('=');
        string cur = s.substr(pos+1);
        int k = stoi(cur);
        if(n>k)return 0;
        if(n==k)return 1;
        // cout<<k<<" "<<n<<endl;
        return C(k-1,n-1);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends