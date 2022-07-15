// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long int minSum(int arr[], int n)
    {
        // Your code goes here
        
        sort(arr,arr+n);
        long long int ans=0;
        long long int a =0;
        long long int b =0;
        vector<long long int >pow((n+1)/2,0);
        pow[0]=1;
        for(int i=1;i<(n+1)/2;i++){
            pow[i]=pow[i-1]*10;
        }
        for(int i=n-1;i>=0 ; i--){
            if(i&1){
                ans+=(arr[i]*pow[a]);
                a++;
            }
            else ans+=(arr[i]*pow[b]),b++;
            
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.minSum(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends