//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int maxGroupSize(int arr[], int N, int k) {
        // code here
        
        map<int , int > mp;
        for(int i = 0 ; i  < N  ; i++){
            mp[arr[i] % k]++;
        }
        int ans = 0;
        for(int i = 0 ; i <= k/2 ; i++){
            int cur = i;
            int sec = mp[cur];
            
            if(sec == 0 and mp[k - cur] == 0)continue;
            if(cur == 0 ){
                ans++;
            }
            else if(i * 2 == k){
                ans += 1;
            }
            else{
                ans += max(sec , mp[k - cur]);
            }
            mp[cur] = 0;
            mp[k - cur] = 0;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxGroupSize(arr,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends