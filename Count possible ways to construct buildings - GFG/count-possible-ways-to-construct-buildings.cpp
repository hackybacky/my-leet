// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int  dp[100001];
	int mod =1e9+7;
	int recur(int i ){
	    if(i<=0)return 1;
	    if(dp[i]!=-1)return dp[i];
	    
	    int ans = ( recur(i-1) + recur(i-2) )%mod;
	    
	    return dp[i]=ans%mod;
	}
	int TotalWays(int N)
	{
	    // Code here
	    memset(dp,-1,sizeof(dp));
	    long long int ans = recur(N);
	    return (ans*ans)%mod;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends