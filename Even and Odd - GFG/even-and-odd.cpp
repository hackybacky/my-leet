// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void reArrange(int a[], int N) {
        // code here
        int e=0,o=1;
        
        for(int i=0;i<N; i++){
            
            if(i%2==0){
                e=i;
                while(e<N and a[e]%2!=0)e++;
                swap(a[i],a[e]);
            }
            else{
                o=i;
                while(o<N and a[o]%2!=1)o++;
                swap(a[i],a[o]);
            }
            // for(int i=0 ; i<N ; i++)cout<<a[i]<<" ";
            // cout<<endl;
        }
        
        
        
    }
};

// { Driver Code Starts.

int check(int arr[], int n)
{
    int flag = 1;
    int c=0, d=0;
    for(int i=0; i<n; i++)
    {
        if(i%2==0)
        {
            if(arr[i]%2)
            {
                flag = 0;
                break;
            }
            else
                c++;
        }
        else
        {
            if(arr[i]%2==0)
            {
                flag = 0;
                break;
            }
            else
                d++;
        }
    }
    if(c!=d)
        flag = 0;
        
    return flag;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        ob.reArrange(arr,N);
        
        cout<<check(arr,N)<<endl;
    }
    return 0;
}  // } Driver Code Ends