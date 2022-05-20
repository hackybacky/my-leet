// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findTime(string S1, string S2) {
        // code here
        int ans=0;
        vector<int> key(26);
        
        for(int i=0; i<S1.size(); i++)key[S1[i]-'a']=i;
        
        // int ans=0;
        int prev =0;
        for(auto it : S2){
            int cur= key[it-'a'];
            ans+=abs(prev-cur);
            prev=cur;
        }
        
        return ans;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1,S2;
        cin>>S1;
        cin>>S2;

        Solution ob;
        cout<<ob.findTime(S1,S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends