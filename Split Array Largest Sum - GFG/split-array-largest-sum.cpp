//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
        int low = 0 , high = 1e9;
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;
            
            int dk = 1;
            int cur = 0;
            bool flag = false;
            for(int i = 0 ; i < N ; i++){
                if(arr[i] > mid){
                    flag = true;
                }
                if(cur + arr[i] <= mid){
                    cur += arr[i];
                }
                else{
                    dk++;
                    cur = arr[i];
                }
            }
            if(dk <= K and !flag ){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends