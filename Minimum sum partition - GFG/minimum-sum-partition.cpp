//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    vector<vector<int >> dp;
    int sum = 0;
    int recur(int i , int su , int arr[] , int n ){
        if(i == n ){
            return abs(sum - su - su);
        }
        if(dp[i][su] != -1){
            return dp[i][su];
        }
        int ans = min(recur(i + 1 , su + arr[i] , arr , n ) , recur(i + 1 , su , arr , n));
        return dp[i][su] = ans;
    }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    
	    for(int i = 0 ; i < n ;i++){
	        sum += arr[i];
	    }
	    dp.assign(n + 1 , vector<int>(sum , -1));
	    int ans = recur(0 , 0 , arr , n);
	    return ans;
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends