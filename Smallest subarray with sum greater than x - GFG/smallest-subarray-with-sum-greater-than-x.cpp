//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here   
        int l = 0 ; 
        int sum = 0;
        
        int ans = INT_MAX;
        int r = 0;
        while(r < n){
            bool flag = false;
            if(sum <= x){
                sum += arr[r++];
                flag = true;
            }
            else{
                sum -= arr[l++];
            }
            if(sum > x){
                ans = min(ans , r - l );
            }
            
            // cout << sum <<" " << l <<" "<<r << endl;
        }
        while(l < n and sum - arr[l] > x){
            sum -= arr[l];
            l++;
            ans = min(ans , r - l);
        }
        if(ans == INT_MAX){
            ans = 0;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends