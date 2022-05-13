// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int MaxGold(vector<vector<int>>&matrix){
    // Code here
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>>dp(n,vector<int>(m,-1));
    int ans=0;
    for(int i=0 ; i<n ; i++ ){
        for(int j=0; j<m; j++){
            if(i==0 ){
                dp[i][j]=matrix[i][j];
            }
            else {
                if(matrix[i][j]==-1){dp[i][j]=-1;continue;}
                int a = dp[i-1][j];
                int b = (j-1>=0?dp[i-1][j-1]:-1);
                int c = (j+1<m ? dp[i-1][j+1]:-1);
                
                if(a==-1 and b==-1 and c==-1){dp[i][j]=-1;continue;}
               
                dp[i][j]=matrix[i][j];
                dp[i][j]+=max({a,b,c});
            }
            
            ans=max(ans,dp[i][j]);
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
		int m, n;
		cin >> m >> n;
		vector<vector<int>>matrix(m, vector<int>(n, 0));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++)
				cin >> matrix[i][j];
		}
		Solution obj;
		int ans = obj.MaxGold(matrix);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends