// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minVal(int a, int b) {
        // code here
        int ba = __builtin_popcount(a);
        int bb = __builtin_popcount(b);
        
            int ans=0;
        if(ba>=bb){
            for(int i=30;i>=0 ; i--){
                int d = (1<<i);
                if(a&d and bb){
                    bb--;
                    ans|=d;
                }
                
                    
            }
        }
        else{
            ans=a;
            int last=0;
            int rem = bb-ba;
            for(int i=0;i<=30;i++){
                int d = 1<<i;
                if(!(d&a) and rem>0){
                    ans|=(d);
                    rem--;
                }
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
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}  // } Driver Code Ends