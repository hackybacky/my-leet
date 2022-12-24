//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    vector<int> x = {1, -1, 0, 0};
vector<int> y = {0, 0, 1, -1};
    void dfs(int curx , int cury , vector<vector<int>> &mat ){
        if(curx < 0 or cury < 0 or cury >= mat[0].size() or curx >= mat.size()){
            return ;
        }
        if(mat[curx][cury] == 0)return ;
        mat[curx][cury] = 0;
        for(int k = 0 ; k < 4 ; k++){
            int nx = curx + x[k];
            int ny = cury + y[k];
            dfs(nx , ny , mat);
        }
    }
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        
        for(int i = 0 ; i < N ; i++){
            // if(matrix[i][0] or matrix[i][M - 1]){
                dfs(i , 0 , matrix);
                dfs(i , M - 1, matrix);
            // }
        }
        for(int i = 0 ;i < M ; i++){
            dfs(0 , i , matrix);
            dfs(N - 1 , i , matrix);
        }
        int cnt = 0;
        for(int i = 1 ;i < N - 1 ; i++){
            for(int j = 1 ; j < M - 1; j++){
                if(matrix[i][j] == 1){
                    dfs(i , j , matrix);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends