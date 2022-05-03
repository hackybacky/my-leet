// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
    int dp[210][5000];
    int k;
    int n;
    int recur(int i , int cur,vector<int>&arr){
        if(i==n){
         //  cout<<cur<<endl;
            if(cur==k)return 1;
            return 0;
        }
        if(dp[i][cur]!=-1)return dp[i][cur];
        
        return dp[i][cur]=(recur(i+1,cur^arr[i],arr)+recur(i+1,cur,arr));
    }
    int subsetXOR(vector<int> arr, int N, int K) {
        // code 
        n=N;
        k=K;
        memset(dp,-1,sizeof(dp));
        
        return recur(0,0,arr);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}  // } Driver Code Ends