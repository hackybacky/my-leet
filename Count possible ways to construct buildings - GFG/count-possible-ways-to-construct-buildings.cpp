// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int  dp[100001];
	int mod =1e9+7;
// 	int recur(int i ){
// 	    if(i<=0)return 1;
// 	    if(dp[i]!=-1)return dp[i];
	    
// 	    int ans = ( recur(i-1) + recur(i-2) )%mod;
	    
// 	    return dp[i]=ans%mod;
// 	}
	int TotalWays(int N)
	{
	    // Code here
	    memset(dp,0,sizeof(dp));
	    dp[0]=1;
	    for(int i=1;i<=N;i++){
	        dp[i]=(dp[i-1]+dp[i])%mod;
	        dp[i]=(dp[i]+(i-2>=0?dp[i-2]:1))%mod;
	    }
	    long long int  ans = dp[N]%mod;
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