//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    vector<int>pref(n , 0);
	    vector<int>cur;
	    for(int i = n - 1 ;i >=0 ; i--){
	        
	        auto it = lower_bound(cur.begin() , cur.end() , nums[i]);
	        if(it == cur.end()){
	            cur.push_back(nums[i]);
	        }
	        else{
	            *it = nums[i];
	        }
	        pref[i] = cur.size();
	    }
	    int ans = 0;
	    vector<int>cur2;
	    for(int i = 0 ;i < n ; i++){
	        auto it = lower_bound(cur2.begin() , cur2.end() , nums[i]);
	        if(it == cur2.end()){
	            cur2.push_back(nums[i]);
	        }
	        else{
	            *it = nums[i];
	        }
	        ans = max(ans , pref[i] + (int)cur2.size() - 1);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends