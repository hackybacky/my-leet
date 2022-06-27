// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int dp[201][201];
    int recur(int f, int e  ){
        if(e==1)return f;
        if(f<=1)return f;
        if(dp[f][e]!=-1)return dp[f][e];
        
        int l=1,r=f;
        int ans = INT_MAX;
        while(l<=r){
            int mid = (l+r)/2;
            int left = recur(mid-1,e-1);
            int right = recur(f-mid,e);
            int cur = 1+max(left,right);
            if(left<=right){
                l=mid+1;
            }
            else r=mid-1;
            ans=min(ans,cur);
        }
        return dp[f][e]=ans;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        memset(dp,-1,sizeof(dp));
        return recur(k,n);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends