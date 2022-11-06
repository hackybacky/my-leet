//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        stack<int> st;
        int n = heights.size();
        int ans = 0;
        for(int i = 0 ; i < n ;i++){
            int cur = heights[i];
            while(!st.empty() and heights[st.top()] > cur){
                int right = i;
                int curt = heights[st.top()];
                st.pop();
                int left = -1;
                if(!st.empty()){
                    left = st.top();
                }
                ans = max(ans , (right - left - 1 ) * curt);
            }
            st.push(i);
        }
        return ans;
            
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        vector<int>heights(m , 0);
        // vector<int
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m; j++){
                if(M[i][j] == 1){
                    heights[j] += 1;
                }
                else heights[j] = 0;
            }
                ans = max(ans , largestRectangleArea(heights));
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends