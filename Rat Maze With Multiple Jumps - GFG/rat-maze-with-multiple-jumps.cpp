// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int n,m;
    vector<vector<int>>sol;
    bool dfs(int i,int j , vector<vector<int>>&matrix){
        if(i==n-1 and j==m-1  ){sol[i][j]=1;return true;}
        if(i>=n or j>=m or j<0 or i<0 or matrix[i][j]==0)return false;
        bool ans=false;
        sol[i][j]=1;
        for(int k=1;k<=matrix[i][j];k++){
            
            int nx = i+k;
            
            if(dfs(i,j+k,matrix))return true;
            if(dfs(nx,j,matrix))return true;
            
            if(ans)return ans;
        }
       sol[i][j]=0;
        return false;
        
        
    }
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix){
	   // Code 
	   n = matrix.size();
	   m = matrix[0].size();
	   sol.assign(n,vector<int>(m,0));
	   if(dfs(0,0,matrix))return sol;
	   return {{-1}};
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends