//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int ans = 0 , ans2 = 0;
        for(int i = 0 ;i < n ;i++){
            int cur = abs(arr[i]) - 1;
              if(arr[cur] < 0){
                ans = cur + 1;
                
            }
            else
            arr[cur] *= -1;
        }  
        // 
        
        for(int i = 0 ;i < n ;i++){
            if(arr[i] > 0){
                ans2 = i + 1;
                break;
            }
        }
        
        int  *ans3 = new int[2];
        ans3[0] = ans ;
        ans3[1] = ans2;
        // cout << ans << " " << ans2 << endl;
        // return ans3;
        return ans3;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends