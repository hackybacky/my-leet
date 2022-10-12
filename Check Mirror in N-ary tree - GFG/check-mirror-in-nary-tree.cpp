//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
int e;
class Solution {
  public:
  
    int dfs(int root , int root2 , int A[] , int B[]){
        
        if(root >= 2 * e){
            return true;
        }
        
        if(A[root] != B[root2]){
            return false;
        }
        
        return dfs(2 * root + 2 , 2 * root2 + 1 , A , B) & dfs(2 * root + 1 , 2 * root2 + 2 , A ,B);
    }
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        map<int , stack<int>>mp;
        
        for(int i = 0 ; i < 2 * e ; i+= 2){
            mp[A[i]].push(A[i + 1]);
        }
        
        for(int i = 0 ; i < 2* e ; i += 2){
            if(mp[B[i]].empty()){
                return 0;
            }
            int cur = mp[B[i]].top();
            if(cur != B[i + 1]){
                return 0;
            }
            mp[B[i]].pop();
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends