//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        deque<int > q;
        for(int i = 0 ; i < k  ; i++){
            int cur = arr[i];
            while(!q.empty() and arr[q.back()] < cur){
                q.pop_back();
            }
            q.push_back(i);
        }
        vector<int >ans;
        ans.push_back(arr[q.front()]);
        for(int  i = k ; i < n ; i++){
            int cur = arr[i];
            while(!q.empty() and q.front() <= i - k)q.pop_front();
            while(!q.empty() and arr[q.back()] < cur){
                q.pop_back();
            }
            q.push_back(i);
            ans.push_back(arr[q.front()]);
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends