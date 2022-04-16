// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int dp[501];
    int n;
    int k;
    int recur(int i,int j,vector<int>&nums){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        int su=0;
        int ans=INT_MAX;
        for(int j=i; j<n;j++){
            su+=nums[j];
            if(k-su<0)break;
            if(j<n-1)
            ans=min(ans,(k-su)*(k-su)+recur(j+1,j-i+1,nums));
            else ans=0+recur(j+1,j-i+1,nums);
            
            su++;
        }
        return dp[i]=ans;
    }
    int solveWordWrap(vector<int>nums, int K) 
    { 
        // Code here
        n=nums.size();
        k=K;
        memset(dp,-1,sizeof(dp));
        int ans=recur(0,0,nums);
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<=n; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends