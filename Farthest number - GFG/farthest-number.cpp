// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{   
  public:
    
    vector<int> farNumber(int N,vector<int> Arr){
        //code here
        vector<int>a(N,-1);
        vector<int>ans(N,-1);
        for(int i=N-1;i>=0;  i--){
            a[i]=min(Arr[i],(i+1<N?a[i+1]:INT_MAX));
            // cout<<a[i]<<endl;
            auto it = upper_bound(a.begin()+i+1,a.end(),Arr[i]-1);
            ans[i]=(prev(it))-a.begin();
            if(ans[i]==i)ans[i]=-1;
        }
        return ans;
        
        
    }
};

// { Driver Code Starts.
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++)
            cin>>Arr[i];
        Solution obj;
        vector<int> answer=obj.farNumber(N,Arr);
        for(auto i:answer)
            cout<<i<<" ";
        cout<<endl;
  }
}  // } Driver Code Ends