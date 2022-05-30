// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dp[101][101];
    vector<int> x = {1, -1, 0, 0};
    vector<int> y = {0, 0, 1, -1};
    int n ,m;
    int recur(int i , int j , vector<vector<int>>&matrix ){
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=0;
        for(int k =0 ; k< 4; k++){
            int nx = x[k]+i;
            int ny = y[k]+j;
            if(nx<0 or ny<0 or ny>=m or nx>=n)continue;
            
            if(matrix[nx][ny]>matrix[i][j]){
                ans=max(ans,1+recur(nx,ny,matrix));
            }
        }
        return dp[i][j]=ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // Code here
        memset(dp,-1,sizeof(dp));
        n=matrix.size();
        m = matrix[0].size();
        int ans = 1;
        for(int i=0;i < n ; i++ ){
            for(int j=0 ; j<m; j++){
                ans=max(ans,recur(i,j,matrix)+1);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>matrix(n, vector<int>(m, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)cin >> matrix[i][j];
		Solution obj;
		int ans = obj.longestIncreasingPath(matrix);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends