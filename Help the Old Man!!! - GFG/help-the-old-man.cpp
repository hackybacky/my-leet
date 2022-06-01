// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++FLKAJDAFASDFA

class Solution{
public:
    int f,t;
    void toh(int n , int from , int to , int aux ,int& op){
        if(n==0 )return ;
        toh(n-1,from , aux, to , op);
        op--;
        // vector<int>ans;
        if(op==0){
            f= from , t = to;
            return;
        }
        toh(n-1,aux , to , from , op);
        
    }
    vector<int> shiftPile(int N, int n){
        // code here
     toh(N,1,3,2,n);
     return {f,t};
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends