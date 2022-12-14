//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        // code here
        
        int bal = 0;
        int alltime = 0;
        int end = -1;
        int start = 0;
        int endstart = 0;
        for(int i = 0 ; i < n ; i++){
            char c = str[i];
            if(c == '1'){
                bal--;
            }
            else{
                bal++;
            }
            if(bal > alltime){
                alltime = bal;
                endstart = start;
                end = i;
            }
            if(bal < 0){
                bal = 0;
                start = i + 1;
            }
        }
        if(end == -1){
            return {-1};
        }
        return {endstart + 1 , end + 1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends