// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int dp[101][901];
	int recur(int i , string &s,int prev){
	    if(i>=s.size())return 1;
	    if(dp[i][prev]!=-1)return dp[i][prev];
	    int ans=0;
	    int cur=0;
	    for(int k=i;k<s.size();k++){
	        cur+=(s[k]-'0');
	        if(cur>=prev){
	            ans+=recur(k+1,s,cur);
	        }
	    }
	    return dp[i][prev]=ans;
	    
	}
	int TotalCount(string str){
	    // Code here
	    memset(dp,-1,sizeof(dp));
	    return recur(0,str,0);
	    
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends