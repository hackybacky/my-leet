//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};
    void dfs(int curx , int cury , int n , int m , vector<vector<char>>&mat){
        if(curx < 0 or cury < 0 or curx >= n or cury >= m or mat[curx][cury] == 'X' or mat[curx][cury] == '#')return;
        mat[curx][cury] = '#';
        for(int k = 0 ; k < 4 ; k++){
            int nx = curx + x[k];
            int ny = cury + y[k];
            dfs(nx , ny , n , m , mat);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        for(int i = 0 ; i < n ;i++){
            if(mat[i][0] == 'O'){
                dfs(i , 0 , n , m  , mat);
            }
            if(mat[i][m - 1] == 'O'){
                dfs(i , m - 1, n ,m , mat);
            }
        }
        for(int i = 0 ; i < m; i++){
            if(mat[0][i] == 'O')dfs(0 , i , n , m , mat);
            if(mat[n - 1][i] == 'O')dfs(n - 1, i , n , m , mat);
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ;j < m ;j++){
                if(mat[i][j] == 'O')mat[i][j] = 'X';
                if(mat[i][j] == '#')mat[i][j] = 'O';
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends