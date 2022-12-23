//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int dp[302][302];
    int recur(int l , int r , vector<int>&arr){
        
        if(l > r )return 0;
        if(dp[l][r] != -1)return dp[l][r];
        
        for(int k = l ; k <= r ; k++){
            
            int cur = arr[k];
            int left = l - 1 >=0 ? arr[l - 1] : 1;
            int right = r + 1 < arr.size() ? arr[r + 1] : 1;
            dp[l][r] = max(dp[l][r] , cur * left * right + recur(l , k - 1 ,arr) + recur(k + 1, r , arr) );
        }
        return dp[l][r];
        
    }
    int maxCoins(int N, vector<int> &arr) {
        // code 
        memset(dp , -1 ,sizeof(dp));
        return recur(0 , N - 1, arr);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends