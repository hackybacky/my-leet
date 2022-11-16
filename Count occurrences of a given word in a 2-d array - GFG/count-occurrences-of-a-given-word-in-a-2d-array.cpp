//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int ans = 0;
    void dfs(int i , int j , int k , vector<vector<char >> &mat , string & target){
        
        if(i < 0 or j < 0 or j >= mat[0].size() or i >= mat.size() or mat[i][j] == '#' or mat[i][j] != target[k] ){
            return ;
        }
        if(k == target.size() - 1){
            ans++;
            return;
        }
        // cout << k << endl;
        
        mat[i][j] = '#';
        
        dfs(i + 1 , j , k + 1 , mat , target);
        dfs(i , j + 1, k + 1, mat , target);
        dfs(i , j - 1, k + 1 , mat , target);
        dfs(i - 1, j , k + 1 , mat , target);
        
        mat[i][j] = target[k];
        
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        ans = 0;
        for(int i = 0 ; i < mat.size() ; i++){
            for(int j = 0 ; j < mat[0].size() ; j++){
                dfs(i , j , 0 , mat , target);
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
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends