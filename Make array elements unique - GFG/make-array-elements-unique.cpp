//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        set<int>st;
        
        sort(arr.begin() , arr.end());
        queue<int>q;
        long long ans = 0;
        for(int i = 1 ;i < N ; i++){
            if(arr[i] == arr[i - 1]){
                q.push(arr[i]);
            }
            else{
                int d = ( arr[i - 1] + 1);
                while(!q.empty() and d < arr[i]){
                    ans += (long long )(d - q.front());
                    q.pop();
                    d++;
                }
            }
        }
        int d = arr.back() + 1;
        while(!q.empty()){
            ans += ( d - q.front());
            d++;
            q.pop();
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minIncrements(arr, N) << endl;
    }
}
// } Driver Code Ends