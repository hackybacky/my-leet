// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int dp[200001];
    bool recur(int cur, int n , int k , int m , vector<int>&a ){
        
        if(cur>=n){
            return 1;
        }
        
        if(dp[cur]!=-1)return dp[cur];
        
        int l = cur+k-1;
        auto up = upper_bound(a.begin(),a.end(),a[cur]+m);
        auto rup = prev(up);
       
        int r = rup - a.begin();
        int ans=0;
        int ll = l,rr=r;
        while(l<=r){
            int mid =(l+r)/2;
            ans|=recur(mid+1,n,k,m,a);
            if(ans==0)l=mid+1;
            else break;
        }
        l=ll,r=rr;
        while(l<=r){
            int mid =(l+r)/2;
            ans|=recur(mid+1,n,k,m,a);
            if(ans==0)r=mid-1;
            else break;
        }
    return dp[cur]  = ans;      
        
        
    }
    bool partitionArray(int N, int K, int M, vector<int> &a){
        // code here
        sort(a.begin(),a.end());
        memset(dp,-1,sizeof(dp));
        auto ans = recur(0,N,K,M,a);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}
  // } Driver Code Ends