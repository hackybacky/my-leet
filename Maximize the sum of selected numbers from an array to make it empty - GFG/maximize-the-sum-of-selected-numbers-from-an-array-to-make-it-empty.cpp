//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
  

// } Driver Code Ends
class Solution{
    public:
    int maximizeSum(int a[], int n) 
    {
        // Complete the function
        vector<int>dp(1e5 + 1 , 0);
        int ans = 0;
        for(int i = 0 ; i < n ;i++){
            dp[a[i]]++;
            // ans = max(ans , dp[a[i]]);
        }
        int i = 1e5 ;
        while(i > 0){
            if(dp[i] > 0){
                ans += i;
                dp[i - 1]--;
                dp[i]--;
            }
            else{
                i--;
            }
        }
        
        return ans;
        
    }

};


//{ Driver Code Starts.



int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr, arr+n);
        Solution ob;
        
        cout << ob.maximizeSum(arr, n) << endl;
        
        
    }

}


// } Driver Code Ends