// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string movOnGrid(int r, int c) {
        // code here
        int remr = (r-1)%7;
        int remc = (c-1)%4;
        
        if(remr!=remc)return"JON";
        return "ARYA";
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        Solution ob;
        cout<<ob.movOnGrid(r,c)<<endl;
    }
    return 0;
}
  // } Driver Code Ends