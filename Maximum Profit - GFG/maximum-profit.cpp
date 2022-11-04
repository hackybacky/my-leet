//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dp[501][401];
    int n ;
    int recur(int i , int k , int A[] , int K){
        if(i >= n){
            
            return 0;
        }
        // cout << A[i] << endl;
        if(k >= 2 * K){
            return 0;
        }
        // cout << dp[i][k] << endl;
        if(dp[i][k] != -1){
            // cout << k <<" "<< i << endl;
            return dp[i][k];
        }
        int ans = 0;
        int ans2 = recur(i + 1 , k , A ,K);
        if(k % 2 == 0){
            ans = -A[i] + recur(i + 1 , k + 1 , A , K);
        }
        else{
            ans = A[i] + recur(i + 1 , k + 1 , A , K);
        }
        return dp[i][k] = max(ans , ans2);
        
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        n = N;
        memset(dp, -1 ,sizeof(dp));
        return recur(0 , 0 , A , K);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends