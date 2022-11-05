//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int l = 0 , r = m - 1;
	    int cnt = 0;
	    int ans = -1;
	    while( l < n and r >=0 ){
	        bool flag = false;
	        while(r >=0 and arr[l][r] == 1){
	            r--;
	            cnt++;
	            flag = true;
	            ans = l;
	        }
	        if(!flag){
	            l++;
	        }
	        
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends