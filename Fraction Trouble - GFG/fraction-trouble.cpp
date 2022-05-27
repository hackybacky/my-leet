// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
        // code here
        
        double x = (n*1.0)/(d*1.0);
        vector<int>ans;
        double last=0;
        for(int i=d; i<=10000; i++){
            int cy = i;
            int cx = (n*cy)/d;
            
            double fa = (cx*1.0)/(cy*1.0);
            if(fa<x and __gcd(cx,cy)==1 and fa>last){
                ans={cx,cy};
                last=fa;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends