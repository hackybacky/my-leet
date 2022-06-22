// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        int cnta=0,cntb=0,cntc=0;
        int mod = 1e9+7;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a')cnta=(1+(2*cnta)%mod);
            else if(s[i]=='b') cntb = (cnta+(2*cntb)%mod)%mod;
            else cntc=(cntb+(cntc*2)%mod)%mod;
            
        }
        return cntc;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends