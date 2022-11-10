//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long jumpingNums(long long X) {
        // code here
        
        queue<int> q;
        
        for(int i = 1 ; i <= 9 ; i++){
            q.push(i);
        }
        int ans = INT_MIN;
        while(!q.empty()){
            
            int f = q.front();
            q.pop();
            ans = max(ans , f);
            int rem = f % 10;
            int no = f * 10 +rem + 1;
            int no2 = f * 10+ rem  - 1;
            
            if(rem == 9){
               
                if(no2 <= X){
                    q.push(no2);
                }
            }
            else if(rem == 0){
                if(no <= X){
                    q.push(no);
                }
            }
            else{
                
                if(no <= X){
                    q.push(no);
                }
                if(no2 <= X){
                    q.push(no2);
                }
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
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.jumpingNums(X) << endl;
    }
    return 0;
}
// } Driver Code Ends