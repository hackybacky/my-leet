//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends




int first(int arr[] , int n , int x ){
    int l = 0 , r = n - 1;
    int ans = -1;
    while(l <= r){
        int mid = (l + r)/2;
        if(arr[mid] >= x){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}
int last(int arr[] , int n , int x ){
    int l = 0 , r = n - 1;
    int ans = -1;
    while(l <= r){
        int mid = (l + r)/2;
        if(arr[mid] > x){
    
            r = mid - 1;
        }
        else{
            ans = mid;
            l = mid + 1;
        }
    }
    return ans;
}
vector<int> find(int arr[], int n , int x )
{
    // code here
    
    vector<int>ans;
    ans.push_back(first(arr , n , x));
    ans.push_back(last(arr , n , x));
    if(ans[0] >=0 and ans[0] < n and arr[ans[0]] == x){
        return ans;
    }
    return {-1 , -1};
    
    
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends