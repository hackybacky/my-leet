//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // code here
        N--;
        int l = 1 , r = 1e4 ;
        while(l <= r){
            int mid = (l +r )/2;
            int sq = mid * mid;
            if(sq <= N){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return l - 1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends