// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        int max_su=INT_MIN;
        for(int startRow=0;startRow<R ; startRow++){
            vector<int>col_sum(C,0);
            
            for(int endRow=startRow; endRow<R ; endRow++){
                for(int col =0; col<C; col++){
                    col_sum[col]+=M[endRow][col];
                }
                int cur_su=0;
                for(auto it:col_sum){
                    cur_su+=it;
                    max_su=max(max_su,cur_su);
                    if(cur_su<0){
                        cur_su=0;
                    }
                    
                }
            }
        }
        return max_su;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends