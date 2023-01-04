//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    static bool cmp(vector<int>&a , vector<int>&b){
        return a[1] < b[1] or (a[1] == b[1] and a[2] >= b[2]);
    }
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        sort(intervals.begin() , intervals.end() , cmp);
        map<int , int > dp;
        dp[0] = 0;
        int maxi = 0;
        // dp[intervals[0][1]] = intervals[0][2];
        for(int i = 0 ; i < n ; i++){
            auto it2 = intervals[i];
            int start = it2[0] , end = it2[1] , profit = it2[2];
            auto it = dp.lower_bound(start + 1 );
            
            it = prev(it);
                
            dp[end] = max(profit + (*it).second , maxi);
            
            maxi = max(dp[end] , maxi);
            // else dp[end] = max(profit , (*dp.rbegin()).second);
            
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends